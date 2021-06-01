	AREA RESET,DATA,READONLY
	EXPORT __Vectors

__Vectors
	
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler	

Reset_Handler
	
	LDR R0, =SRC	;r0 is pointer to ith element
	LDR R1, =S	
	LDR R2,[R1]		;r2 stores number of elements
	LDR R7, =DST
	MOV R8,#0
Up	CMP R8,R2
	BEQ Wod
	ADD R8,#1
	LDR R9,[R0],#4
	STR R9,[R7],#4
	B Up
Wod	LDR R0,=DST
	MOV R1, R0		;r1 is pointer to element to swap
	MOV R3,R0		;r3 is pointer to jth element
	MOV R10,#0		;r10 is counter for inner(j) loop
	MOV R11,#0		;r11 is counter for outer(i) loop
Com	CMP R11, R2		;comparing i<10
	BEQ STOP		
	ADD R3,R0,#4	;sets jth pointer to A[i+1]
	MOV R1,R0		;sets swap element to A[i]
	ADD R10,R11,#1	;j=i+1
Moc	CMP R10,R2		;j<10
	BEQ Dow
	ADD R10,#1		;j++
	LDR R4,[R3],#4
	LDR R5,[R1]
	CMP R5,R4
	BLT Moc
	MOV R1,R3
	SUB R1,#4
	B Moc
Dow	ADD R11,#1
	LDR R4,[R0]
	LDR R5,[R1]
	STR R4,[R1]
	STR R5,[R0],#4
	B Com
		
STOP B STOP

S DCD 0xA
SRC DCD 0x30,0x29,0x28,0x27,0x26,0x25,0x24,0x23,0x22,0x21
	
	AREA mydata,DATA,READWRITE

DST DCD 0,0,0,0,0,0,0,0,0,0
	END