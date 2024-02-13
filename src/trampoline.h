#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <stdint.h>
extern char jumpLocation;
extern char trampolineFunction;
extern char trampolineFunctionEnd;

char* generateFunction(char* redirect,char* buffer,size_t buffer_size);
#define TRAMPFUNCSIZE  (&trampolineFunctionEnd-&trampolineFunction)
#define GET_REGISTER(var,reg) __asm__("movq %%" #reg ",%0" :"=m"(var))