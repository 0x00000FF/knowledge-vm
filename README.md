# Knowledge Virtual Machine
programmable 16bit pseudo virtual machine. I made it just for *fun*

it has pc(program counter), ac(accumulator), and ir(instruction register).
every datas(includes instructions) are stored in 16bit integer array(also called as "memory"), statically sized in 4096.

program starts from 0th address of memory, and it terminates when it encounters opcode 0.

# Opcodes
if opcode requires parameter, marked with @

| Opcode | Description                                      |
|--------|--------------------------------------------------|
| 0      | terminate program                                |
| 1@     | jump to address if ac equals 0                   |
| 2@     | jump to address if ac larger than 0              |
| 3@     | jump to address if ac lesser than 0              |
| 4      | add 1 to ac                                      |
| 5      | subtract 1 from ac                               |
| 6@     | add value to ac from address                     |
| 7@     | sub value from ac from address                   |
| 8@     | store value to address from ac                   |
| 9@     | load value to ac from address                    |
| A      | print character from ac matches with ASCII code. |
| B@     | set 16bit integer to address from user input     |


# How to Program it
every instructions are 4-digit hex value, such as 1231 (jump to 0x231th address if ac qeuals 0)

parameter can be skipped if the opcode does not require any parameter.

to stop pushing instructions, type `-1`


# HELLO WORLD (can be optimized)
```
4 4 4 4 4 4 4 4 4 4 8300

6300 8301 6301 6301 6300 4 4 A


5 5 5 A


4 4 4 4 4 4 4 A A


4 4 4 A


9302 6301 6300 4 4 A


6301 6301 6300 4 4 4 4 4 A


9302 6301 6301 6301 6301 5 A


4 4 4 A


5 5 5 5 5 5 A


5 5 5 5 5 5 5 5 A -1
```

# Why "Knowledge"?

Absolutely from "Patchouli Knowledge", the name of the character who I really love.
