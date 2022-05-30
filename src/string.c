#include "../include/string.h"
#include <string.h>
#include <stdlib.h>
/**
 * @brief string
 * @param buff_len the total length of the buffer.
 * @param str_len  the string len in the buffer.
 */
struct string {
    char * buffer;
    size_t buff_len;
    size_t str_len; 
};

String newString(const char* clone) {
    String ret;
    if(!clone)
        return NULL;
    ret = calloc(1,sizeof(struct string));
    ret->buff_len = strlen(clone) + 1;
    ret->str_len  = ret->buff_len-1;
    ret->buffer = calloc(ret->buff_len,sizeof(char));
    if(!ret->buffer) {
        free(ret);
        return NULL;
    }
    strcpy(ret->buffer,clone);
    return ret;
}
void StringDestroy(String S) {
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
        if(S1->buff_len <= str_len) {
            temp = realloc(S1->buffer,(str_len+1)*sizeof(char));
            if(!temp)
                return NULL;
            memset(temp,0,str_len+1);
            S1->buff_len = str_len+1;
            S1->buffer = temp;
        }
        S1->str_len = str_len;
        strcpy(S1->buffer,S2->buffer);
    }
    return  S1;
}
char * StringGetIt(String S) {
    if(S && S->buffer) {
        return S->buffer;
    }
    return NULL;
}
size_t StringHash(String S) {
    size_t ret = 0;
    const char *it;
    if(S && S->buffer) {
        it = S->buffer;
        while(*it) {
            ret += ((*it) % 12 ) + 1;
            it++;
        }
    }
    return ret; 
}
size_t StringLen(String S) {
    if(S) {
        return S->str_len;
    }
    return 0;
}

String StringCat(String dest,String src) {
    char *temp;
    if(!dest || !src)
        return NULL;
    if(dest->buff_len - dest->str_len -1 < src->str_len )  {
        dest->buff_len += src->str_len;
        temp = realloc(dest->buffer,dest->buff_len);
        if(!temp) {
            dest->buff_len -= src->str_len;
            return NULL;
        }
        dest->buffer = temp;
    }
    strcat(&dest->buffer[dest->str_len],src->buffer);
return dest;
}

String StringCatCs(String dest,const char * src) {
    size_t src_len;
    char *temp;
    if(!dest || !src)
        return NULL;
    src_len = strlen(src);
    if(dest->buff_len - dest->str_len -1 < src_len )  {
        dest->buff_len += src_len;
        temp = realloc(dest->buffer,dest->buff_len);
        if(!temp) {
            dest->buff_len -= src_len;
            return NULL;
        }
        dest->buffer = temp;
    }
    strcat(&dest->buffer[dest->str_len],src);
return dest;
}