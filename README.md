# Knowledge Virtual Machine
programmable 32bit pseudo virtual machine, successor of 16bit version. I made it just for *fun*

Although this version of knowledge-vm design has no connection with 16bit legacy, it just succeeded the name.

## Usage

```
knowledge-vm --memory=<bytes=4096> --cycles=<per_second=300> 
             --input=<file_descriptor_no_or_filename=0>
             --output=<file_descriptor_no_or_filename=1>
             --log=<log_level: none, verbose, warning, error = none>
             --rom=<basic_knowledge_vm_program_binary>
             --endian=<little, big = little>
```


## Register Structure

it has 8 x 32bit general integer registers(`r0~r7`), 8 x 32bit float registers (`x0~x7`), return register(`rr`) which points address of an instruction to be jumped into after current procedure ends, three control registers(`cp`, `cm`), one state register(`sr`), 3 segment registers like x86's (`cs`, `ss`, `ds`) and a program counter (`ip`). it can has dynamically sized memory which starts its address with 1. it can get input from several external streams so that interact with internal systems.

it introduced another two registers: stack base pointer (`sbp`) which initially points end of memory address, and the stack top pointer (`stp`). `stp` must not have a value overs `sbp`, or system will halt immediately with setting related control register.

### Size Suffixes with Registers

There are several needs to "split" registers into smaller size, Knowledge VM provides size suffixes to fulfill such requirements. each registers are sized in 32bits, and you can halve these into 16bits with `e` suffix. or If you want to utilize in 8 bits, then use `b` suffix. Like x86, Knowledge VM provides `h` and `l` suffixes to specify higher and lower 4 bits in the lowest byte sequence when `b` suffix is assigned.

### Control Register Flags

Knowledge VM provides two control registers `cp` and `cm`.

## Instruction Set Architecture

### Instructions

## Working Flow

### Basic Instruction Process Cycle

### Initial Memory Layout

### Physical Address Determination

#### Segmentation

#### Pagination

### Privilege Level (Protection Ring)

## Example Programs

### Hello World

### Fibonacci Sequence

## Why "Knowledge"?

Absolutely from "Patchouli Knowledge", the name of the character from touhou project, who I really love.

## License of the 16bit legacy version

16bit version of knowledge-vm is distributed under public domain. you can freely redistribute, or modify.