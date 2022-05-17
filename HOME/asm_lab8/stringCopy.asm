.686
.MODEL FLAT, C
.STACK
.DATA
extern malloc: proc
extern free: proc
.CODE
stringCopy PROC
; Стек:
;	адрес возврата (0)
;	char*		dst		(+4)
;	const char*	src		(+8)
;	size_t		amount	(+12)

mov ecx, [esp + 12]
push ecx
call malloc

pop ecx
mov esi, [esp + 8]
mov edi, eax
rep movsb

mov ecx, [esp + 12]
mov esi, eax
mov edi, [esp + 4]
rep movsb

push eax
call free
pop eax

ret
stringCopy ENDP
END
