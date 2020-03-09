// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

//Setting the argument

//STEP 1
@R2
M=0

//STEP 2
@counter // M = counter

//STEP 3
(LOOP)

//STEP 4
@counter
D=M // D = counter

//STEP 5
@R1
D=D-M // D = counter-M

//STEP 6
@END
D;JGE // if counter >= 0 or if R1 >= END

////////////////////////////////////////////////////

//STEP 7
@counter
M=M+1 // counter++
@R0
D=M // D=R0

//STEP 8
@R2
M=M+D // R2=R2+R0

//STEP 9
@LOOP

//STEP 10
0;JMP

(END)
@END

0;JMP









