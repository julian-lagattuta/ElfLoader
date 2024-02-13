#include "customfunctions.h"
#include <stdio.h>
//TODO: HANDLE THREAD LOCAL STORAGE
//INITLIIE PTHREADS HEARD AND LOCAL STORAGE
//PT_TLS 
//import undocumented relocation: TPOFFSET64 
//read auxvec and init library based auxvecs (RANDOM)
//my own version of https://codebrowser.dev/glibc/glibc/csu/libc-start.c.html#234
int __libc_start_main()
{
    int __attribute__((sysv_abi)) (*main)(int, char** ,char** ,void*);
    uint64_t argc;
    char** argv;
    auxv_t* auxves;
    int __attribute__((sysv_abi)) (*init)(int, char** ,char** ,void*);
    void __attribute__((sysv_abi)) (* fini)(void);
    void __attribute__((sysv_abi)) (*rtld_fini) (void);
	void *stack_end;
    //glibc sysdeps/x86_64/start.S
    // main:		%rdi
	// argc:		%rsi
	// argv:		%rdx
	// init:		%rcx
	// fini:		%r8
	// rtld_fini:	%r9
	// stack_end:	stack.	*/
    
    GET_REGISTER(main,rdi);
    GET_REGISTER(argc,rsi);
    GET_REGISTER(argv,rdx);
    GET_REGISTER(init,rcx);
    GET_REGISTER(fini,r8);
    GET_REGISTER(rtld_fini,r9);
    auxv_t* auxvec;
    char** environ = &argv[argc+1];
    char **evp = environ;
    while(*evp++ != NULL);
    auxvec = evp;



    exit(main(argc,argv,environ,auxvec));
}

// int __attribute__((sysv_abi)) puts_abi(const char* s){
//     return puts(s);
// }
typedef uint64_t u64;
typedef float fl;
void __cdecl testfunc(u64 a, u64 b,u64 c,u64 d, u64 e,u64 p,fl g,fl h, fl i, fl j,fl k,fl l){
    putchar(a);
}