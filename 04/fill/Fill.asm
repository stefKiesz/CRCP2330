// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

//Initialize i
//Index runs on the screen's pixels

(INIT)

//32 * 256 of 16 bit to cover the screen 	
@8192	
D=A

//Initializ the index to 8192
//Remaining address left to color onscreen
@i                  
M=D

//Sending index back.
(LOOP)

@i
M=M-1
D=M
@INIT

//If index < 0, reset index initializer
D;JLT

//Load keyboard's address
@KBD	            
D=M

//If keyboard == 0)/ no keypressed, go WHITE, else go BLACK
@WHITE		        
D;JEQ
@BLACK
0;JMP

(BLACK) 

//Load screen's first address: 16384 (0x4000)            
@SCREEN            
D=A
@i

//Add current index to the screen's first address
//Color the current set of 16 bit pixels
A=D+M

//Set value in current address to -1
//All 16 bit pixels will be black              
M=-1 

//Send index back.             
@LOOP              
0;JMP

(WHITE)

//Load screen's first address: 16384 (0x4000)
@SCREEN            
D=A                
@i

//Add current index to screen's first address
//Color the current set of 16 bit pixels        
A=D+M

//Set value in current address to 0
//All 16 bit pixels will be white.             
M=0

//Send index back.                  
@LOOP           
0;JMP