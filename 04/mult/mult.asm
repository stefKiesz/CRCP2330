// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

//Making a counter
//Initializing i with value in R1

@R1
D=M

@i
M=D

//Initilaizing product with 0
@R0
D=A
@product
M=D

(LOOP)
// if i <= 0, get out of LOOP
@i
D=M
@END
D;JLE

















