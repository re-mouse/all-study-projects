section .text
global _ft_strcmp

_ft_strcmp:	xor rax, rax
			xor rcx, rcx
_loop:
			mov	al, byte[rdi]
			mov cl, byte[rsi]
			sub rax, rcx
				jnz exit
			cmp cl, 0
				je exit
			inc rdi
			inc rsi
			jmp _loop

exit: ret