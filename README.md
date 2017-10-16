# Knowledge Virtual Machine
programmable 16bit pseudo virtual machine

it has pc(program counter), ac(accumulator), and ir(instruction register).
every datas(includes instructions) are stored in 16bit integer array, it sizes 4096.

program starts from 0th address of memory, and it terminates when it encounters opcode 0.
parameter can be skipped if the opcode does not require any parameter.

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
