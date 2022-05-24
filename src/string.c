#include "../include/string.h"
#include <string.h>
#include <stdlib.h>
struct string {
    char * buffer;
    size_t buff_len; /* not the string len, but maximum string len -1 */
};

String newString(const char* clone) {
    String ret;
    if(!clone)
        return NULL;
    ret = calloc(1,sizeof(struct string));
    ret->buff_len = strlen(clone) + 1;
    ret->buffer = calloc(ret->buff_len,sizeof(char));
    if(!ret->buffer) {
        free(ret);
        return NULL;
    }
    strcpy(ret->buffer,clone);
    return ret;
}
void   StringDestroy(String S) {
    free(S->buffer);
    free(S);
}

int StringCmpCs(String S1,const char *S2) {
    return strcmp(S1->buffer,S2);
}
int StringCmp(String S1, String S2) {
    return strcmp(S1->buffer,S2->buffer);
}
void StringPrint(String S,FILE *StreamOut) {
    if(S && S->buffer && StreamOut)
        fprintf(StreamOut,"%s",S->buffer);
}
void StringPrintLn(String S,FILE *StreamOut) {
    if(S && S->buffer && StreamOut)
        fprintf(StreamOut,"%s\n",S->buffer);
}
String StringCopy(String S1, String S2) {
    size_t str_len;
    char * temp;
    if(S1 && S2) {
        /* need S1 buff len to be > S2 strlen */
        str_len = strlen(S2->buffer);
        if(S1->buffer <= str_len) {
            temp = realloc(S1->buffer,(str_len+1)*sizeof(char));
            if(!temp)
                return NULL;
            memset(temp,0,str_len+1);
            S1->buff_len = str_len+1;
            S1->buffer = temp;
        }
        strcpy(S1->buffer,S2->buffer);
    }
}
char * StringGetIt(String S) {
    if(S && S->buffer) {
        return S->buffer;
    }
    return NULL;
}