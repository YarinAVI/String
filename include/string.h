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
/**
 * @brief copies S2 to S1.
 * 
 * @param S1 dest string.
 * @param S2 source string.
 * @return String returns S1 if copy was succesfull, NULL otherwise.
 */
String StringCopy(String S1, String S2);

String StringCopyCs(String S1,const char *S2);

int StringCmpCs(String S1,const char *S2);

/**
 * @brief returns pointer to first character.
 * 
 * @param S the string.
 * @return char* ptr.
 */
char * StringGetIt(String S);
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
/**
 * @brief returns hash of S.
 * 
 * @param S the string
 * @return size_t the hash.
 */
size_t StringHash(String S);

/**
 * @brief returns the current string length.
 * 
 * @param S the string.
 * @return size_t length.
 */
size_t StringLen(String S);

/**
 * @brief concats src to dest.
 * 
 * @param dest dest string.
 * @param src source string.
 * @return String dest string if sucessful, NULL otherwise.
 */
String StringCat(String dest,String src);

/**
 * @brief concats src to dest
 * 
 * @param dest dest string.
 * @param src source string ( const char *).
 * @return String dest string if sucessful, NULL otherwise. 
 */
String StringCatCs(String dest,const char * src);

#ifdef __cplusplus
}
#endif
#endif