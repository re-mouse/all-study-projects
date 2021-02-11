	global _ft_strcpy
	section .text

_ft_strcpy:	mov rcx, rdi
sravni:		cmp byte[rsi], 0
			ja	copyandinc
			mov byte[rdi], 0
			mov rax, rcx
			ret

copyandinc:	mov	al, byte[rsi]
			mov byte[rdi], al
			inc rdi
			inc rsi
			jmp sravni