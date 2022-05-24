/*
 * @Author: Yarin Avisidris
 * @Date: 2022-05-18 23:20:54
 * @Last Modified by: Yarin Avisidris
 * @Last Modified time: 2022-05-19 00:05:52
 */

#ifndef __STRING__H_
#define __STRING__H_
#include <stddef.h>
#include <stdio.h>
#ifdef __cplusplus
extern "C"
{
#endif
typedef struct string * String;
/**
 * @brief creates a new String.
 * 
 * @param clone a C string to make into our String object.
 * @return String returns our String object.
 */
String newString(const char* clone);
/**
 * @brief deallocates a string, completely.
 * 
 * @param S the string.
 */
void   StringDestroy(String S);

String StringCopy(String S1, String S2);

String StringCopyCs(String S1,const char *S2);

int StringCmpCs(String S1,const char *S2);

/**
 * @brief compares two strings by using strcmp.
 * 
 * @param S1 first string.
 * @param S2 second string.
 * @return int val returned from strcmp.
 */
int StringCmp(String S1, String S2);

/**
 * @brief prints a string.
 * 
 * @param S string.
 * @param StreamOut the stream. 
 */
void StringPrint(String S,FILE *StreamOut);
/**
 * @brief prints a string and adds a new line.
 * 
 * @param S string.
 * @param StreamOut the stream. 
 */
void StringPrintLn(String S,FILE *StreamOut);
#ifdef __cplusplus
}
#endif
#endif