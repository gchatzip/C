/*Giorgos Xatzipantelis 
  AM:2489
  Assignment2       */
/* FILE NAME:       */
/* Module Mystring.h*/
/*Setting the types to * or [] has no difference as those two types are equal when it comes to function arguments */

/*Including here the libraries will make the files that include this library to also include this files */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stddef.h>
#include<string.h>

/*Cheked runtime erros is done by asserting*/
/*Asserting to all functions is like this:assert(pcStr)*/
/*This happens because NULL and FALSE are identical */


/*Returns the length(bytes contained by) of the pcStr */
/*Cheked runtime error:if pcStr is NULL */
size_t ms_length(const char *pcStr);

/*Copies pcCt to pcStr including '\0'character.Returns pcStr */
/*Cheked runtime error:if pcStr and pcCt are NULL */
char *ms_copy(char *pcStr,const char *pcCt);

/*Copies up to n characters of pcCt to pcStr It also adds the null terminating character.If pcCt has less than n characters the rest are filled up with '\0'. */
/*Returns pcStr*/
/*If pcCt has less than n characters it fills up with '\0' */
char *ms_ncopy(char *pcStr,const char *pcCt,size_t n);

/*Concats pcCt at the end of pcStr.Returns pcStr */
/*Checked runtime error:if pcstr and pcCt are null*/
char *ms_concat(char *pcStr,const char *pcCt);

/*Concats up to n characters of pcCt with pcStr and terminates pcStr with '\0'.Returns s. */
char *ms_nconcat(char *pcStr,const char *pcCt,size_t n);

/*Compares pcStr with pcCt  */
/*    RETURNS:       */
/*<0  if pcStr<pcCt  */
/* 0  if pcStr==pcCt */
/* 0> if pcStr>pcCt  */
/*Checked runtime erros:If pcStr and pcCt are null */
int ms_compare(const char *pcStr,const char *pcCt);

/*Compares up to n characters of pcStr with pcCt */
/*   RETURNS:        */
/*<0  if pcStr<pcCt  */
/* 0  if pcStr==pcCt */
/* 0>  if pcStr>pcCt  */
/*Checked runtime erros:If pcStr and pcCt are null */
int ms_ncompare(const char *pcStr,const char *pcCt,size_t n);

/*Returns pointer to the first occurance of pcCt into pcStr or returns NULL if there is no occurance at all */
/*It is a checked runtime error for pcStr and pcCt to be NULL */
const char *ms_search(const char *pcStr,const char *pcCt);
