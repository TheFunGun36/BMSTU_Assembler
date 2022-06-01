.686
.MODEL FLAT, C
.STACK
.CODE
stringLength PROC
; Стек:
;    адрес возврата (0)
;    строка (+4)
mov ecx, 07fffffffh
mov edi, [esp + 4]
mov eax, 0
repnz scasb
mov eax, 07fffffffh
sub eax, ecx
dec eax
ret
stringLength ENDP
END
