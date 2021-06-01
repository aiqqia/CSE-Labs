	AREA RESET, CODE, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	
	AREA myCode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =SRC
	LDR R2, =KEY
	MOV R4, #9
	LDR R3, [R2]
Up	TEQ R4, #0
	BEQ Don
	LDR R1, [R0], #4
	TEQ R1, R3
	BEQ Fon
	SUB R4, #1
	B Up
Fon	MOV R5, #1
Don	TEQ R5, #1
	BEQ Yes
	MOV R4, #0
	B No
Yes	RSB R4, #10
	LDR R6, =DST
	SUB R4,#1
	STRB R5, [R6], #1 ;Stores 1 for found, 0 for not found
	STRB R4, [R6]     ;Stores Index Value of the number if found
	B STOP
No	LDR R6, =DST
	STR R7, [R6]
	
STOP B STOP
SRC	DCD 34, 25, 23, 46, 15, 46, 27, 98, 89
KEY DCD 23
	AREA MYDATA, DATA, READWRITE
DST DCD 0
	END