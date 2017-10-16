#include <stdio.h>
#define INFINITE_LOOP  1

typedef __int8_t  byte;
typedef __int16_t int16;

byte  sigkill = 0;

#ifdef  _MSVC_
__declspec(align(8))
#else
__attribute__ ((aligned (8)))
#endif
int16 memory[4096], pc = 0, ir, ac = 0;

void program()
{
    #ifdef  _MSVC_
        __declspec(align(8))
    #else
        __attribute__ ((aligned (8)))
    #endif
    int16 input, index=0;

    while (INFINITE_LOOP)
    {
        scanf("%x", &input);

        if (input == -1) {
            memory[index] = 0;
            break;
        } else {
            memory[index++] = input;
        }
    }
}

void check(const int16 pc)
{
    if (pc > 4096)
    {
        printf("illegal pc value, machine terminated.");
        sigkill = 1;
    }
}

void execute(const int16 instruction)
{
    byte opcode;
    int16 ax;

    opcode = (byte)(instruction < 0x1000 && instruction > 0 ? (__uint16_t)instruction : ((__uint16_t )instruction >> 12));
    ax = instruction - (opcode << 12);

    switch (opcode)
    {
        case 0x0: // exit
            sigkill = 1;
            break;

        case 0x1: // jez (addr)
            if (!ac)
                pc = ax;
            break;

        case 0x2: // jgz (addr)
            if (ac > 0)
                pc = ax;
            break;

        case 0x3: // jlz (addr)
            if (ac < 0)
                pc = ax;
            break;

        case 0x4: // inc
            ac++;
            break;

        case 0x5: // dec
            ac--;
            break;

        case 0x6: // add (addr)
            ac += *(memory + ax);
            break;

        case 0x7: // sub (addr)
            ac -= *(memory + ax);
            break;

        case 0x8: // set (addr)
            *(memory + ax) = ac;
            break;

        case 0x9: // get (addr)
            ac = *(memory + ax);
            break;

        case 0xA: // prn
            putchar(ac);
            break;

        case 0xB: // inp (addr)
            scanf("%d", (memory + ax));
            break;

        default:
            printf("\nwarning : undefined opcode %x, ignored\n", opcode);
            break;
    }
}

int main(void)
{
    printf("Knowledge 16bit Pseudo-Machine\nProgrammed by P.Knowledge, 2016-\n\n");
    program();

    while (!sigkill)
    {
        ir = memory[pc++];
        execute(ir);

        check(pc);
    }
}
