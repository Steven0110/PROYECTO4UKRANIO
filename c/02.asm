.include "m8535def.inc"
ser DDRA
ser DDRC
ciclo: in R17, PINB
	in R18, PIND
	MOV R16, R17
	ADD R16, R18
	in R15, SREG
	out PORTA, R16
	out PORTC, R15
	rjmp ciclo