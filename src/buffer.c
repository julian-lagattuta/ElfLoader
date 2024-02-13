#include "buffer.h"
#define LINUX 1
void* largeAlloc(size_t size){
#ifdef _WIN64   
    SYSTEM_INFO s;

    GetSystemInfo(&s);
    DWORD gran = s.dwAllocationGranularity;
    size+=gran-size%gran;
   
return VirtualAlloc(NULL,size,MEM_COMMIT |MEM_RESERVE,PAGE_EXECUTE_READWRITE );
#endif
#ifdef __unix__

    printf("UNIX NOT SUPPORTED");
#endif
}
void largeFree(void* p,size_t size){
#ifdef _WIN64
    if(!VirtualFree(p,size,MEM_RELEASE)){
        printf("ERROR FREEING!");
    }
#endif

#ifdef __unix__
    printf("UNIX NOT SUPPORTED");
#endif
}
    