.686
.MODEL FLAT, C
.STACK
.CODE
stringCopy PROC
; Стек:
;	адрес возврата (0)
;	char*		dst		(+4)
;	const char*	src		(+8)
;	size_t		amount	(+12)

mov edi, [esp + 4]
mov esi, [esp + 8]
mov ecx, [esp + 12]

loop_begin:
	mov al, [esi]
	mov [edi], al
	inc esi
	inc edi
	loop loop_begin
ret
stringCopy ENDP
END
