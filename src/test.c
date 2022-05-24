#include "../include/string.h"
#include <stdlib.h>
int main(int argc,char **argv) {
    String *x = malloc(argc * sizeof(void*));
    for(int i=0;i<argc;i++) {
        x[i] = newString(argv[i]);
    }
    for(int i=0;i<argc;i++) {
        StringPrintLn(x[i],stdout);
    }
    for(int i=0;i<argc;i++) {
        StringDestroy(x[i]);
    }
    free(x);
}