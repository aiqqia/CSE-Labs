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
    MOV R0,#10 ;Numerator
	MOV R1,#3  ;Denominator
    MOV R2,#0 ;Quo
	MOV R3,#0 ;Rem
	LDR R4, =QUO
	LDR R5, =REM
UP	CMP R0,R1
	BCC Sto
	SUBS R0,R1
	ADD R2,#1;Quo
	B UP
Sto	MOV R3,R0
	STR R2,[R4]
	STR R3,[R5]
STOP B STOP 
    AREA MYDATA, DATA, READWRITE 
QUO DCD 0
REM DCD 0
	END