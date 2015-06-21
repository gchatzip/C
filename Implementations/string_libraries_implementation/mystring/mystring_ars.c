/* Giorgos Xatzipantelis 
   AM:2489
   Assignment2
   mystring_ars.c     */

#include "mystring.h"

/*Returns the length(bytes contained by) of the pcStr */
/*Cheked runtime error:if pcStr is NULL */
size_t ms_length(const char pcStr[])
{
  size_t uiLength=0U;
  assert(pcStr!=NULL);
  while (pcStr[uiLength]!='\0')
    uiLength++;
  return uiLength;
}/*End of ms_length*/

/*Copies pcCt to pcStr including '\0'character.Returns pcStr */
/*Cheked runtime error:if pcStr and pcCt are NULL */
char *ms_copy(char pcStr[],const char pcCt[])
{
  size_t i=0U;
  assert(pcStr);
  assert(pcCt);
 
  while ((pcStr[i]=pcCt[i]))
    i++;
  
  return pcStr;


}/*End of ms_copy*/

/*Copies up to n characters of pcCt to pcStr It also adds the null terminating character.If pcCt has less than n characters the rest are filled up with '\0'. */
/*Returns pcStr*/
/*If pcCt has less than n characters it fills up with '\0' */
char *ms_ncopy(char pcStr[],const char pcCt[],size_t n)
{
  size_t i=0U;
  assert(pcStr);
  assert(pcCt);

  if (n>0){
    while ((pcStr[i]=pcCt[i])){
      i++;
      if (i==(n-1))
	break;
    }/*End while*/
    pcStr[n]='\0';
    if (ms_length(pcCt)<n){/* case that pcCt has less characters than n */
      while (i<=n){
        pcStr[n]='0';
        i++;
      }
    }
    return pcStr;
  }/*End if*/
  else 
    printf("Error\n");
    exit(-1);

}/*End of ms_ncopy*/

/*Concats pcCt at the end of pcStr.Returns pcStr */
/*Checked runtime error:if pcstr and pcCt are null*/
char *ms_concat(char pcStr[],const char pcCt[])
{
  size_t i=0U;
  size_t j=0U;
  assert(pcStr);
  assert(pcCt);

  i=ms_length(pcStr);
  
  while (j<=ms_length(pcCt)){
    pcStr[i]=pcCt[j];
    j++;
  }/*End while */
  


}/*End of ms_concat*/

/*Concats up to n characters of pcCt with pcStr and terminates pcStr with '\0' first character of pcCt overrides the null terminating character of pcStr.
/* Returns pcStr */
/*Checked runtime error:if pcStr and pcCt are null*/
char *ms_nconcat(char pcStr[],const char pcCt[],size_t n)
{
  size_t i=0U;
  size_t j=0U;

  assert(pcStr);
  assert(pcCt);
  
  i=ms_length(pcStr);
  if (n>0){
    while (j<=n)){
      pcStr[i]=pcCt[j];
      j++;
      i++;
      if(j==n)
        break;
    }/*End while */
    pcStr[i]='\0';
    return pcStr;
  }/*End IF */
  else 
   printf("error!\n");
   exit(-1);
}/*End of ms_nconcat */

/*Compares pcStr with pcCt  */
/*    RETURNS:       */
/*<0  if pcStr<pcCt  */
/* 0  if pcStr==pcCt */
/* 0> if pcStr>pcCt  */
/*Checked runtime erros:If pcStr and pcCt are null */
int ms_compare(const char pcStr[],const char pcCt[])
{
 
  
  size_t i ;
  assert(pcStr);
  assert(pcCt);

  for (i = 0U; pcStr[i] == pcCt[i] && pcStr[i] != '\0' && pcCt[i] != '\0';  i++) /* if pcStr character is the same with pcCt character and its not the null terminating */
    ;                                                                            /*increment the index                                                                  */
  
  return pcStr[i] - pcCt[i];
}/*End of ms_compare */

/*Compares up to n characters of pcStr with pcCt */
/*   RETURNS:        */
/*<0  if pcStr<pcCt  */
/* 0  if pcStr==pcCt */
/* 0>  if pcStr>pcCt  */
/*Checked runtime erros:If pcStr and pcCt are null */
int ms_ncompare(const char pcStr[],const char pcCt[],size_t n)
{
  size_t i ;
  assert(pcStr);
  assert(pcCt);

  for (i = 0U; pcStr[i] == pcCt[i] && pcStr[i] != '\0' && pcCt[i] != '\0' && i<n ;  i++) /* if pcStr character is the same with pcCt character and its not the null terminating */
    ;                                                                            /*increment the index                                                                  */
  
  return pcStr[i] - pcCt[i];

}/*End ms_ncompare */

/*Returns pointer to the first occupation of pcCt in pcStr*/
/*If pcCt is not occupied in pcStr NULL is returned */
/*Cheked runtime erros:if pcCt and pcStr are NULL */

const char *ms_search(const char pcStr[],const char pcCt[])
{
  size_t i;
  size_t h;
  
  assert(pcStr);
  assert(pcCt);
                                    

  if (pcCt[0]=='\0') return *pcStr;

  for(i=0U;i<ms_length(pcStr);i++){
    if ((pcStr[i]==pcCt[i] && pcCt[i]!='\0' )){
      for(h=i;h<ms_length(pcStr)&&pcStr[i]==pcCt[i];h++){
	if (h==ms_length(pcCt))
              return *pcStr;
      }/*End nested for */
    }/*End if */
  }/*End for */ 
  return NULL;       
}/*End ms_search */



