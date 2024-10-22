#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/headers.h"

int main(int argc, char *argv[]) {
typedef struct error_buffs {
    char buffs[15];
    int in;

} buffer, *ptr_buffers;
    struct error_buffs * buffers;

    unsigned int len;
    len = (*buffers).in;

    strcpy((buffers)->buffs, argv[1]); // <- HOW MUCH DATA CAN BE HANDLE BY BUFFS -> buffs[15]
    printf("\n[STRING_PRINT] - [%s]\n", (buffers)->buffs);
    printf("[HEXSTR_PRINT] - [%x]\n", (buffers)->buffs);

    // (*buffers).len = strlen((buffers)->buffs);
    len = strlen((buffers)->buffs);
    if (len > 15) { // if ((*buffers).len > 15) {
	    printf("[DEBUG] Address Of Data [0%08x] (STATUS) [+] Buffer Overflow\n", &(buffers)->buffs);
        printf("String Length [%d]+[0%08x]\n", strlen((*buffers).buffs), (buffers)->buffs);
    } else {
        printf("[DEBUG] Address Of Data [0%08x] (STATUS) [-] Buffer Overflow\n", &(buffers)->buffs);
        printf("String Length [%d]+[0%08x]", strlen((*buffers).buffs), (buffers)->buffs);
    }
    return 0;
}