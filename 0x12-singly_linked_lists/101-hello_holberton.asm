section .data
	acd db "Hello, Holberton", 0

section .text
	extern printf
	global main

main:
	mov edi, acd
	call printf
	mov eax, 0
	ret
