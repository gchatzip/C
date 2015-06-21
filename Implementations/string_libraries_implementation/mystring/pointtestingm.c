#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stddef.h>
#include<string.h>

size_t ms_length(const char *pcStr);
char *ms_copy(char *pcStr,const char *pcCt);
char *ms_ncopy(char *pcStr,const char *pcCt,size_t n);
int ms_compare(const char *pcStr,const char *pcCt);
int ms_ncompare(const char *pcStr,const char *pcCt,size_t n);
char *ms_concat(char *pcStr,const char *pcCt);
char *ms_nconcat(char *pcStr,const char *pcCt,size_t n);
const char *ms_search(const char *pcStr,const char *pcCt);


int main(void){

  /* char *s1 = (char *)malloc(100*sizeof(char)); 
     char *s2; */
  char *s1=(char *)malloc(100*sizeof(char));
  char *s2=(char *)malloc(100*sizeof(char));
  printf("Give the string :\n");
  gets(s1);
  printf("Give the string:\n");
  gets(s2);


  printf("%s\n",ms_search(s1,s2));
  return 1;
}/*End main */

size_t ms_length(const char *pcStr)
{
  const char *pcStrEnd=pcStr;
  
  assert(pcStr!=NULL);
  
  while (*pcStrEnd!='\0')
    pcStrEnd++;
  
  return pcStrEnd-pcStr;

}/* End of ms_length */
char *ms_copy(char *pcStr,const char *pcCt)
{
  char *s=pcStr;
  
  assert(pcStr);
  assert(pcCt);
 
  while ((*pcStr++=*pcCt++))
    ;

  return s;

}/*End of ms_copy */


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
  }
  return sc;
  
  
}/* End of ms_ncopy */
int ms_compare(const char *pcStr,const char *pcCt)
{
  for(; *pcStr==*pcCt; pcStr++,pcCt++)
    if (*pcStr=='\0') /* we reached null terminating character and the strings are still equal so return 0  */
      return 0;
  return *pcStr-*pcCt;
        

}/*End of ms_compare */


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

char *ms_concat(char *pcStr,const char *pcCt)
{
  char *pcN=pcStr;
 
  assert(pcStr);
  assert(pcCt);
  
  pcStr = ms_copy(pcStr + ms_length(pcStr),pcCt);
  
  return pcN;
  

}/* End of ms_concat */
char *ms_nconcat(char *pcStr,const char *pcCt,size_t n)
{
  char *pcN=pcStr;
  
  assert(pcStr);
  assert(pcCt);

  pcStr=ms_ncopy(pcStr+ms_length(pcStr),pcCt,n);
  
  return pcN;


}/*End of ms_nconcat */

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






