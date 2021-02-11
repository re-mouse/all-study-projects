global	_ft_strlen
section .text

_ft_strlen:	mov	rcx, 0
comp:		cmp byte[rdi], 0
			jne incr
			mov rax, rcx
			ret
incr:	inc rdi
		inc rcx
		jmp comp