#include "trampoline.h"


char* generateFunction(char* redirect,char* buffer,size_t buffer_size){
    static size_t buffer_index =0;
	memcpy(&buffer[buffer_index],&trampolineFunction,&trampolineFunctionEnd-&trampolineFunction);
    uint64_t* offset = (uint64_t* )(&jumpLocation-&trampolineFunction+buffer+buffer_index);
    *offset = redirect;
    buffer_index+=TRAMPFUNCSIZE;
	return &buffer[buffer_index-TRAMPFUNCSIZE];
    
}
typedef uint64_t u64;
typedef float fl;
//THIS FUNCTION SHOULD NOT BE CALL, i JUST USE IT TO MODIFY THE ASSMELBY OF THE COMPILED VERSON OF THIS FUNCTIOn



