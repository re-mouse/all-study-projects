extern ___error
section .text
global _ft_read

_ft_read:	mov rax, 0x2000003
			syscall
			jc seterrno
			ret

seterrno:	push rax
			call ___error
			pop rbx
			mov [rax], rbx
			mov rax, -1
			ret