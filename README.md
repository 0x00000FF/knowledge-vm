# Knowledge Virtual Machine
programmable 32bit pseudo virtual machine, successor of 16bit version. I made it just for *fun*

Although this version of knowledge-vm design has no connection with 16bit legacy, it just succeeded the name.

## Usage

```
knowledge-vm --memory=<bytes=4096> --cycles=<per_second=300> 
             --input=<file_descriptor_no_or_filename=0>
             --output=<file_descriptor_no_or_filename=1>
             --log=<log_level: none, verbose, warning, error>
             --rom=<basic_knowledge_vm_program_binary>
```


## Register Structure

it has 8 x 32bit general integer registers(r0~r7), 8 x 32bit float registers (x0~x7), return register(rret), two control registers(ca, cf) and a program counter (ip). it can has dynamically sized memory which starts its address with 1. it can get input from several external streams so that interact with internal systems.

it introduced another two registers: stack base pointer (sbp) which initially points end of memory address, and the stack top pointer (stp). `stp` must not have a value overs `sbp`, or system will halt immediately with control.

### Size Suffixes with Registers

### Control Register Flags

## Instruction Set Architecture

### Instructions

## Working Flow

## Example Programs

### Hello World

### Fibonacci Sequence

## Why "Knowledge"?

Absolutely from "Patchouli Knowledge", the name of the character from touhou project, who I really love.
