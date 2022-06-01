EXTRN BUF: byte
PUBLIC print

SCPRNT SEGMENT para public 'CODE'
	assume CS:SCPRNT
print proc far
    push ax
    push dx

    mov ax, seg BUF
    mov es, ax

    mov dh, es:BUF + 4
    sub dh, es:BUF + 5
    add dh, '0'

    mov ah, 02h
    
    mov dl, 0Ah
    int 21h

    mov dl, 0Dh
    int 21h

    mov dl, dh
    int 21h

    pop dx
    pop ax
    ret
print endp
SCPRNT ENDS
END