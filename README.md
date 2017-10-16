# Knowledge Virtual Machine
programmable 16bit pseudo virtual machine

it has pc(program counter), ac(accumulator), and ir(instruction register).
every datas(includes instructions) are stored in 16bit integer array, it sizes 4096.

program starts from 0th address of memory, and it terminates when it encounters opcode 0.
parameter can be skipped if the opcode does not require any parameter.

# Opcodes
if opcode requires parameter, marked with @

`exit`, opcode 0 : terminate program

`jez`, opcode 1  : @jump to address if ac equals 0

`jgz`, opcode 2  : @jump to address if ac larger than 0

`jlz`, opcode 3  : @jump to address if ac lesser than 0

`inc`, opcode 4  : add 1 to ac

`dec`, opcode 5  : sub 1 from ac

`add`, opcode 6  : @add value to ac from address

`sub`, opcode 7  : @sub value from ac from address

`set`, opcode 8  : @store value to address from ac

`get`, opcode 9  : @load value to ac from address

`prn`, opcode A(10) : print character from ac matches with ASCII code. 

`inp`, opcode B(11) : @set 16bit integer to address from user input
