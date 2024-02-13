#include "elfloader.h"
#include <stdio.h>
#include "datastructures.h"
int main(int argc, char* argv[]){
    printf("");
     if (argc == 1) {
        printf("Please place the executable and all appropriate .so files in run folder.\nUsage: main.exe <filename>");
    } else if (argc == 2) {
        char *filename = argv[1];
        printf("Running executable with filename: %s\n", filename);
        elfLoad(filename);
    } else {
        printf("Please place the executable and all appropriate .so files in run folder.\nUsage: main.exe <filename>");
        
    }
//	printf("%p",largeAlloc(1000));
    return 0;
}
