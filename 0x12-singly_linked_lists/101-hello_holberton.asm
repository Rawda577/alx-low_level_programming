section .data
	hello db "Hello, Holberton", 0

section .text
	extern printf
	global main
main:
	mov edi, hello
	call printf

	mov eax, 0
	ret
