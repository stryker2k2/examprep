;;;;;;;;;;;;;;;;;;;; 
;                  ; 
; WORK IN PROGRESS ;
;                  ;
;;;;;;;;;;;;;;;;;;;;

global _main

section .data
section .bss
section .text
_main:
	mov ebx, fs:0x30	; Get pointer to PEB
	mov ebx, [ebx + 0x0C] ; Get pointer to PEB_LDR_DATA
	mov ebx, [ebx + 0x14] ; Get pointer to first entry in InMemoryOrderModuleList
	mov ebx, [ebx]		; Get pointer to second (ntdll.dll) entry in InMemoryOrderModuleList
	mov ebx, [ebx]		; Get pointer to third (kernel32.dll) entry in InMemoryOrderModuleList
	mov ebx, [ebx + 0x10] ; Get kernel32.dll base address
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
