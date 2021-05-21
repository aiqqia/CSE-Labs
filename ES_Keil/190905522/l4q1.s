	AREA RESET, DATA, READONLY
	EXPORT __Vectors

__Vectors
	DCD 0X10001000
	DCD Reset_Handler

	AREA MYCODE, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=SRC1
	LDR R1,[R0]
	LDR R7,=DST
	MOV R2,#1
	MOV R3,#0xA
	MOV R4,#0
	MOV R5,#0xF
UP	AND R6,R1,R5
	MLA R4,R6,R2,R4
	MUL R2,R3
	LSR R1,#4
	CMP R1,#0
	BNE UP
	STR R4,[R7]
STOP B STOP
SRC1 DCD 0x612
	AREA MYDATA, DATA, READWRITE
DST DCD 0
	END