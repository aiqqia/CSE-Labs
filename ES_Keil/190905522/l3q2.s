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
    LDR R0,=SRC
	LDR R1,=DST
	LDR R2,[R0]
	MLA R3,R2,R2,R2
	LSR R3,#1
	STR R3,[R1]
STOP B STOP
SRC DCD 0x0000000A
    AREA MYDATA, DATA, READWRITE 
DST DCD 0
	END