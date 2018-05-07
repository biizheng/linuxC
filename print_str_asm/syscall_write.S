section .data

str_c_lib	:db	"THIS IS A STRING FORM C_LIB!",0xa
str_c_lib_len equ $ - str_c_lib

str_syscall	:db	"THIS IS A STRING FROM SYSCALL!",0xa
str_syscall_len equ $ - str_syscall

section .text
global _start

_start:
;-----1:simulate using system call to print string

push str_c_lib_len
push str_c_lib
push 1

call simu_write


;--------2:print string right by using system call


mov eax,4
mov ebx,1
mov ecx,str_syscall
mov edx,str_syscall_len
int 0x80




;--------exit

mov eax,1
int 0x80


;---------simulate function-----------------

simu_write:

	push ebp
	mov ebp,esp
	
	mov eax,4
	mov ebx,[ebp+8]
	mov ecx,[ebp+12]
	mov edx,[ebp+16]

	int 0x80
	pop ebp 
	ret

















