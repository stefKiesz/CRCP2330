// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

@sum
//Initializing sum to 0
M=0 

@R1
D=M

@count
//Initializing count to the value of RAM[1]
M=D

(LOOP)

@count
D=M

@END
D;JEQ //If count is 0, go to END

@R0
D=M

@sum
//Adding RAM[0] to sum
M=M+D

@count
//Decrementing count by 1
M=M-1

@LOOP
//Loop Again
0;JMP

(END)

@sum
D=M
@R2
//Sum to RAM 2
M=D




















