extern _malloc
section .text
global	_ft_strdup

_ft_strdup:	push rdi
			jmp _ft_strlen
strlenret:	mov rdi, rax
			inc rdi
			call _malloc
			mov	rdi, rax
			pop rsi
			jmp _ft_strcpy
strcpyret:	ret


_ft_strlen:	mov	rcx, 0
comp:		cmp byte[rdi], 0
			jne incr
			mov rax, rcx
			jmp strlenret
incr:	inc rdi
		inc rcx
		jmp comp


_ft_strcpy:	mov rcx, rdi
sravni:		cmp byte[rsi], 0
			ja	copyandinc
			mov byte[rdi], 0
			mov rax, rcx
			jmp strcpyret


copyandinc:	mov	al, byte[rsi]
			mov byte[rdi], al
			inc rdi
			inc rsi
			jmp sravni