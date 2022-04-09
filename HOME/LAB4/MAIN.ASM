EXTRN print: far 
PUBLIC BUF

SSTK SEGMENT PARA STACK 'STACK'
	db 100 dup(0)
SSTK ENDS

SD SEGMENT PARA PUBLIC 'DATA'
	BUF db 255 dup (255)
SD ENDS

SCM SEGMENT PARA PUBLIC 'CODE'
	assume CS:SCM, DS:SD
main:	
	mov AX, seg SD
    mov DS, AX

    mov DX, 0000h
    mov AH, 0Ah     ;Считали строку
    int 21h

    call print

    mov AX, 4c00h
	int 21h
SCM ENDS
END main