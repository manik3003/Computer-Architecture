# CS204-RISC-V-Assembler
The following project is a course project under the guidance of Dr T.V. Kalyan.
It is a C++ program which can convert a RISC-V(32-bit) Assembly code to its corresponding Machine Code along with Data Memory

## Contributed By
[Anany Dhamija - 2021MCB1231](https://github.com/AnanyDhamija)

[Manik Gupta - 2021MCB1187](https://github.com/manik3003)

## SUPPORTED INSTRUCTIONS-

Our project supports below mentioned instructions:  

`R format` - add, and, or, sll, slt, sra, srl, sub, xor, mul, div, rem

`I format` - addi, andi, ori, lb, ld, lh, lw, jalr

`S format` - sb, sw, sd, sh

`SB format` - beq, bne, bge, blt

`U format` - auipc, lui

`UJ format` - jal

## Assembler Directives:  
- .text
- .data
- .byte
- .half
- .word
- .dword
- .asciiz


## Technology Stack
1. C++  
2. Assembly Language (RISC V ISA)  

`test.asm` file: File that need to be converted into Machine Code.    
`test.mc` file:  File in which the output of program(Machine Code) is given.   

## General Instructions To Run Locally

1. If you do not have the code for this RISC-V assembler, clone the repository and checkout the code:
    ```bash
    git clone URL
    ```

2. Compile the `main.cpp` file using g++:
    ```bash
    g++ main.cpp
    ```

3. Run the executable:
    ```bash
    ./a.out
    ```
4. You are ready with machine code in `test.mc` file, which includes the memory segment as well.

### Running locally on device after downloading the files:  
- You must keep test.asm and main.cpp in the same folder and then run main.cpp.
- The output will be generated in the file named test.mc.
