section .data
	hello db "Hello, Holberton", 0

section .text
	extern printf
	global main
main:
	; Call printf with the address of the hello string as the argument
	mov rdi, hello
	call printf

	; Exit the program
	mov eax, 0
	ret
