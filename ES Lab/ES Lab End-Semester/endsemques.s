    AREA RESET,DATA,READONLY 
	EXPORT __Vectors 
__Vectors 
	DCD 0X10001000 
	DCD Reset_Handler 
	ALIGN 
	AREA MYCODE,CODE,READONLY 
	ENTRY
	EXPORT Reset_Handler 
Reset_Handler 
	LDR R0, =LIST
	LDR R1, =LENGTH
	LDR R2,[R1]
	LDR R7, =CHECKSUM
	MOV R5, #0
UP	LDRB R3, [R0],#1
	ADD R5,R5,R3
	SUBS R2, #1
	BNE UP ;if we have checked all counts of Length then exits the loop
	STRB R5,[R7]
STOP B STOP 
LIST DCB 0x28, 0x55, 0x26, 0x70, 0x45, 0x30, 0x62, 0x85 ;list to store all values
LENGTH DCD 4 ;variable for length
	AREA MYDATA, DATA, READWRITE
CHECKSUM DCD 0 ;variable for answer checksum
	END