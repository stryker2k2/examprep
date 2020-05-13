;;;;;;;;;;;;;;;;;;;; 
;                  ; 
; WORK IN PROGRESS ;
;                  ;
;;;;;;;;;;;;;;;;;;;;

format PE console
use32
entry start

	start:
		; Save all registers
		push eax;
		push ebx;
		push ecx;
		push edx;
		push esi;
		push edi;
		push ebp;
				
		; Establish a new stack frame
		mov ebp, esp
		sub esp, 18h		; Allocate memory on stack for local variables
		
		; Push the function name on the stack
		xor esi, esi
		push esi				; Null termination
		push 63h
		push word 6578h			; "xec"
		push 456e6957h			; "WinE"
		mov [ebp-4], esp		; var4 = "WinExec\x00"
		
		; Find kernel32.dll base address
		xor esi, esi			; esi = 0
		;mov ebx, fs:0x30		; Get pointer to PEB (has NULL value)
		mov ebx, [fs:30h + esi]	; Get pointer to PEB (avoids NULL value)
		mov ebx, [ebx + 0x0C]	; Get pointer to PEB_LDR_DATA
		mov ebx, [ebx + 0x14]	; Get pointer to first entry in "InMemoryOrderModuleList"
		mov ebx, [ebx]			; Get pointer to second (ntdll.dll) entry in "InMemoryOrderModuleList"
		mov ebx, [ebx]			; Get pointer to third (kernel32.dll) entry in "InMemoryOrderModuleList"
		mov ebx, [ebx + 0x10]	; Get kernel32.dll base address
		mov [ebp-8], ebx		; var8 = kernel32 base address
		
		; Find WinExec address
		mov eax, [ebx + 3Ch]	; RVA of PE signature
		add eax, ebx			; Address of PE signature = RVA of PE signature + kernel32 base address (ebx)
		mov eax, [eax + 78h]	; RVA of Export Table
		add eax, ebx			; eax = Address of Export Table
		
		mov ecx, [eax + 24h]	; RVA of Ordinal Table
		add ecx, ebx			; Address of Ordinal Table = RVA of Ordinal Table (ecx) + kernel32 base address (ebx)
		mov [ebp-0Ch], ecx		; var12 = Address of Ordinal Table
		
		mov edi, [eax + 20h]	; RVA of Name Pointer Table
		add edi, ebx			; Address of Name Pointer Table = RVA of Name Pointer Table (edi) + kernel32 base address (ebx)
		mov [ebp-10h], edi		; var16 = Address of Name Pointer Table
		
		mov edx, [eax+1Ch]		; RVA of Address Table
		add edx, ebx			; Address of Address Table = RVA of Address Table (edx) + kernel32 base address (ebx)
		mov [ebp-14h], edx		; var20 = Address of Address Table
		
		mov edx, [eax + 14h]	; Number of exported functions
		
		xor eax, eax			; counter = 0
		
		.loop:
			mov edi, [ebp-10h]		; edi = var16 = Address of Name Pointer Table
			mov esi, [ebp-4]		; esi = var4 = "WinExec\x00"
			xor ecx, ecx
			
			cld						; set DF=0=> process strings from left to right
			mov edi, [edi + eax*4]	; Entries in Name Pointer Table are 4 bytes long
									; edi = RVA Nth entry = Address Name Table * 4
			add edi, ebx			; edi = address of string = base address + RVA Nth entry
			add cx, 8				; Length of strings to compare (len('WinExec') = 8)
			repe cmpsb				; Compare the first 8 bytes of strings in esi and edi registers
									; ZF=1 if equal, ZF=0 if not equal
			
			jz start.found
			
			inc eax					; counter++
			cmp eax, edx			; check if last function (edx) is reached
			jb start.loop			; if not the last -> loop
			
			add esp, 26h			; clear the stack
			jmp start.end			; if last has been check and function not found -> jump to end
			
		.found:
			; the counter (eax) now holds the position of WinExec
			mov ecx, [ebp-0Ch]		; ecx = var12 = Address of Ordinal Table
			mov edx, [ebp-14h]		; edx = var20 = Address of Address Table
			
			mov ax, [ecx + eax*2]	; ax = ordinal number = var12 + (counter * 2)
			mov eax, [edx + eax*4]	; eax = RVA of function = var20 + (ordinal * 4)
			add eax, ebx			; eax = address of WinExec = kernel32 base address + RVA of WinExec
			
			; Load calc.exe
			xor edx, edx
			push edx
			push 6578652eh			; ".exe"
			push 636c6163h			; "calc"
			push 5c32336dh			; "m32\"
			push 65747379h			; "yste"
			push 535c7377h			; "ws\S"
			push 6f646e69h			; "indo"
			push 575c3a43h			; "C:\W"
			mov esi, esp			; esi = "C:\Windows\System32\calc"
			
			; Launch WinExec (calc.exe, SW_SHOWDEFAULT)
			push 10					; Windows state SW_SHOWDEFAULT
			push esi				;"C:\Windows\System32\calc"
			call eax				;WinExec
			
			add esp, 46h			;clear the stack
			
		.end:
			;add esp, 26h			; clear the stack
			pop ebp
			pop edi
			pop esi
			pop edx
			pop ecx
			pop ebx
			pop eax
			ret
			
			
			

; TO COMPILE:
; del *.obj && del *.o && del *.exe
;
; //WIN32
; nasm -f win32 getK32.asm
; ld getK32.obj -o GetK32.exe
;
; //ELF
; nasm -f elf getK32.asm
; gcc getK32.o -o GetK32.exe
;
; //FASM
; fasm getK32.asm Get32.exe
