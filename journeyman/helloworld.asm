global _main
extern _printf

section .data
msg db "Hello, world!!", 0Dh, 0Ah, 0

section .bss
section .text
_main:
	push ebp
	mov ebp, esp
		push msg
		call _printf
		add esp, 4
		
	mov esp, ebp
	pop ebp
ret

; TO COMPILE:
; del *.obj && del *.o && del *.exe
;
; //WIN32
; nasm -f win32 helloworld.asm
; ld helloworld.obj -o HelloWorld.exe
;
; //ELF
; nasm -f elf helloworld.asm
; gcc helloworld.o -o HelloWorld.exe
