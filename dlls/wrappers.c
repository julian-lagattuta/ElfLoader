#include "wrappers.h"

typedef size_t abi_list;

#define abi_start(list,len) (list=len)
#define abi_arg(list,type) 
int ABI puts_abi(char* s){
    return puts(s);
}