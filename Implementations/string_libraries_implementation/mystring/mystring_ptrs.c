/*Giorgos Xatzipantelis
  AM:2489
  Assignment2
  mystring_ptrs.c    */

#include "mystring.h"

/*Returns the length(bytes contained by) of the pcStr */
/*Cheked runtime error:if pcStr is NULL */
size_t ms_length(const char *pcStr)
{
  const char *pcStrEnd=pcStr;

  assert(pcStr!=NULL);

  while (*pcStrEnd!='\0')
    pcStrEnd++;

  return pcStrEnd-pcStr;
} 

/*Copies pcCt to pcStr including '\0'character.Returns pcStr */
/*Cheked runtime error:if pcStr and pcCt are NULL */
char *ms_copy(char *pcStr,const char *pcCt)
{
  char *s=pcStr;
  
  assert(pcStr);
  assert(pcCt);
 
  while ((*pcStr++=*pcCt++))
    ;
  return s;
}/*End of ms_copy */

/*Copies up to n characters of pcCt to pcStr It also adds the null terminating character.If pcCt has less than n characters the rest are filled up with '\0'. */
/*If pcCt has more than n characters the result will NOT be null terminated*/
/*Returns pcStr*/
/*If pcCt has less than n characters it fills up with '\0' */
/*Cheked runtime error:if pcStr and pcCt are NULL */
char *ms_ncopy(char *pcStr,const char *pcCt,size_t n)
{
 
  char *sc=pcStr;
  const char *sc2=pcCt;
  size_t i;

  assert(pcStr);
  assert(pcCt);

  for (i=0U;i<n;i++){
      *pcStr++=*pcCt++;
      if(n>ms_length(sc2))
        for (i=ms_length(sc2);i<n;i++)
	  *pcStr++ = '\0';
  }/*end for */
}/* End of ms_ncopy */

/*Appends pcCt to pcStr.*/
/*The first character of pcCt overwrites the null terminating character of pcStr */
/*Checked runtime error:if pcStr and pcCt are null*/
char *ms_concat(char *pcStr,const char *pcCt)
{
  char *s=s1;
  size_t i;
 
  assert(pcStr);
  assert(pcCt);
  
  for(i=0U;i<ms_length(pcStr);i++)
    *pcStr++;
  for(i=0U;i<ms_length(pcCt)&& *pcStr=*pcCt;i++,pcStr++,pcCt++)
    ;
  *s++='\0';
  return s;

}/* End of ms_concat */

char *ms_nconcat(char *pcStr,const char *pcCt,size_t n)
{

}/*End of ms_nconcat */

/*Compares lexicongraphically byte by byte  pcStr with pcCt  */
/*    RETURNS:       */
/*<0  if pcStr<pcCt  */
/* 0  if pcStr==pcCt */
/* 0> if pcStr>pcCt  */
/*Checked runtime erros:If pcStr and pcCt are null */
int ms_compare(const char *pcStr,const char *pcCt)
{
  assert(pcStr);
  assert(pcCt);

  for(; *pcStr==*pcCt; pcStr++,pcCt++)
    if (*pcStr=='\0') /* We reached the end of strings( null terminating character */
      return 0;       /*and they are equal so return 0                             */
  return *pcStr-*pcCt;
}/*End of ms_compare */

/*Compares lexicongraphically byte by byte  up to n characters of pcStr with pcCt */
/*   RETURNS:        */
/*<0  if pcStr<pcCt  */
/* 0  if pcStr==pcCt */
/* 0>  if pcStr>pcCt  */
/*Checked runtime erros:If pcStr and pcCt are null */
int ms_ncompare(const char *pcStr,const char *pcCt,size_t n)
{
  size_t i=0U;
  size_t j=0U;
  
  assert(pcStr);
  assert(pcCt);
 
  i=ms_length(pcStr);
  j=ms_length(pcCt);
  for(; *pcStr==*pcCt && i<n && j<n; pcStr++,pcCt++ )
    if (*pcStr=='\0')
      return 0;
  return *pcStr-*pcCt;
}/*End of ms_ncompare */

/*Checks if pcCt is occupied in pcStr*/
/* Returns: */
/*Pointer to the first occupation of pcCt in pcStr */
/*Or returns NULL if pcCt is not occupied in pcStr */
/*Cheked runtime erros:if pcStr is NULL and if pcStr is NULL */
const char *ms_search(const char *pcStr,const char *pcCt)
{
  size_t h;

  assert(pcStr);
  assert(pcCt);

  if (*pcCt=='\0' ) return *pcStr;

  if (*pcStr==*pcCt){/* we found the first character occuring */
                     /*now we need to check if the rest characters are same */
    for(h=0U;*(pcStr+h)==*(pcCt+h) && *(pcCt+h)!='\0' ;h++)
      if (h==ms_length(pcCt)) return *pcStr;
  }/*End if */
  return NULL; /* no occurance was found */     
}/*End of ms_search */
