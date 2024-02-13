SECTION .TEXT
GLOBAL trampolineFunction
GLOBAL jumpLocation 
GLOBAL trampolineFunctionEnd
; a modified version of:
; with optimization
; extern uint64_t __cdecl f(u64 a, u64 b,u64 c,u64 d, u64 e,u64 p,fl g,fl h, fl i, fl j,fl k,fl l,fl m,fl n);
; uint64_t __attribute__((sysv_abi)) trampolineFunction(u64 a, u64 b,u64 c,u64 d, u64 e,u64 p,fl g,fl h, fl i, fl j,fl k,fl l,fl m,fl n){
;    return f(a,b,c,d,e,p,g,h,i,j,k,l,m,n);  
; } 
trampolineFunction:	
	pop rax

	sub    rsp,0x68
	mov    QWORD  [rsp+0x28],r9
	mov    r9,rcx
	mov    rcx,rdi
	mov    QWORD  [rsp+0x20],r8
	mov    r8,rdx
	mov    rdx,rsi	
	movss  DWORD  [rsp+0x58],xmm5
	movss  DWORD  [rsp+0x50],xmm4
	movss  DWORD  [rsp+0x48],xmm3
	movss  DWORD  [rsp+0x40],xmm2
	movss  DWORD  [rsp+0x38],xmm1
	movss  DWORD  [rsp+0x30],xmm0

	push rax

	lea rbx, [rel jumpLocation]
	jmp   [rbx]

jumpLocation:
	dq 0x0
trampolineFunctionEnd:
dq 0x0

; rsp:  0x2c20dff978
;0x00000223db321162

; rbp: 0x2c20dff980
;0x0000002c20dffa00


; prev prev rbp <-rbp

; ret addr <- rsp






; prev prev rbp

; ret addr
; prev rbp <- rbp


; variables


; <- rsp






