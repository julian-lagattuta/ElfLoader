
#include <stdio.h>
#include <stdarg.h>
#define ABI __attribute__((sysv_abi))
#define GET_REGISTER(var,reg) __asm__("movq %%" #reg ",%0" :"=m"(var))