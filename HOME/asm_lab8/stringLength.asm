.686
.MODEL FLAT, C
.STACK
.CODE
stringLength PROC
; Стек:
;    адрес возврата (0)
;    строка (+4)
xor eax, eax
mov ebx, [esp + 4] 
loop_begin:
	mov dl, [ebx]
	test dl, dl
	jz loop_end
	inc eax
	inc ebx
	jmp loop_begin
loop_end:
ret
stringLength ENDP
END
