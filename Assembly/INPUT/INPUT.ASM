ORG 00H;
MOV P0,#0;
LOOP: SETB P3.6;
SETB P3.7;
BACK: JNB P3.6,NXT;
LCALL DELAY;
SJMP BACK;

NXT: INC A;
MOV P0,A;
LCALL DELAY;
SJMP LOOP;

ORG 300H;
	DELAY:MOV R0,#255;
	AGAIN:MOV R1,#200;
	HERE:DJNZ R1,HERE;
	DJNZ R0,AGAIN;
	RET;
END;