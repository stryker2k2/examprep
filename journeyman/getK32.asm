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
	; Establish a new stack frame
	push ebp
	mov ebp, esp
	sub esp, 18h			; Allocate memory on stack for local variables
	
	; Push the function name on the stack
	xor esi, esi
	push esi			; Null termination
	push 63h			; "c"
	pushw 6578h			; "xe"
	push 456e6957h			; "WinE"
	mov [ebp-4], esp		; var4 = "WinExec\x00"
	
	; Find kernel32.dll base address
	mov ebx, fs:0x30		; Get pointer to PEB
	mov ebx, [ebx + 0x0C]		; Get pointer to PEB_LDR_DATA
	mov ebx, [ebx + 0x14]		; Get pointer to first entry in "InMemoryOrderModuleList"
	mov ebx, [ebx]			; Get pointer to second (ntdll.dll) entry in "InMemoryOrderModuleList"
	mov ebx, [ebx]			; Get pointer to third (kernel32.dll) entry in "InMemoryOrderModuleList"
	mov ebx, [ebx + 0x10]		; Get kernel32.dll base address
	mov [ebp-8], ebx		; var8 = kernel32 base address
	
	; Find WinExec address
	mov eax, [ebx + 3Ch]		; RVA of PE signature
	add eax, ebx			; Address of PE signature = RVA of PE signature + kernel32 base address (ebx)
	mov eax, [eax + 78h]		; RVA of Export Table
	add eax, ebx			; eax = Address of Export Table
	
	mov ecx, [eax + 24h]		; RVA of Ordinal Table
	add ecx, ebx			; Address of Ordinal Table = RVA of Ordinal Table (ecx) + kernel32 base address (ebx)
	mov [ebp-0Ch], ecx		; var12 = Address of Ordinal Table
	
	mov edi, [eax + 20h]		; RVA of Name Pointer Table
	add edi, ebx			; Address of Name Pointer Table = RVA of Name Pointer Table (edi) + kernel32 base address (ebx)
	
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
