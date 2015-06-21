#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stddef.h>
#include<string.h>


size_t ms_length(const char pcStr[]);
char  *ms_copy(char pcStr[],const char pcCt[]);
char  *ms_ncopy(char pcStr[],const char pcCt[],size_t n);
char  *ms_concat(char pcStr[],const char pcCt[]);
char  *ms_nconcat(char pcStr[],const char pcCt[],size_t n);
int    ms_compare(const char *pcStr,const char *pcCt);
int    ms_ncompare(const char pcStr[],const char pcCt[],size_t n);
const char *ms_search(const char *pcStr,const char *pcCt);


int main(){
  char x[]="hia";
  char y[]="hi";
  printf("%s\n",ms_search(x,y));
  return 1;
}/* END MAIN */

size_t ms_length(const char pcStr[])
{
  size_t uiLength=0U;
  assert(pcStr!=NULL);
  while (pcStr[uiLength]!='\0')
    uiLength++;
  return uiLength;
}/*End of ms_length*/
char *ms_copy(char pcStr[],const char pcCt[])
{
  size_t i=0U;
  assert(pcStr);
  assert(pcCt);
 
  while ((pcStr[i]=pcCt[i]))
    i++;
  
  return pcStr;


}/*End of ms_copy*/
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
    i++;
  }/*End while */
  pcStr[i]='\0';
  return pcStr;
  


}/*End of ms_concat*/

char *ms_nconcat(char pcStr[],const char pcCt[],size_t n)
{
  size_t i=0U;
  size_t j=0U;

  assert(pcStr);
  assert(pcCt);
  
  i=ms_length(pcStr);
  if (n>0){
    while (j<=n){
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

int ms_compare(const char pcStr[],const char pcCt[])
{
 
  
  size_t i ;
  assert(pcStr);
  assert(pcCt);

  for (i = 0U; pcStr[i] == pcCt[i] && pcStr[i] != '\0' && pcCt[i] != '\0';  i++) 
    ;
  
  return pcStr[i] - pcCt[i];
}/*End of ms_compare */
int ms_ncompare(const char pcStr[],const char pcCt[],size_t n)
{
  size_t i ;
  assert(pcStr);
  assert(pcCt);

  for (i = 0U; pcStr[i] == pcCt[i] && pcStr[i] != '\0' && pcCt[i] != '\0' && i<n ;  i++) /* if pcStr character is the same with pcCt character and its not the null terminating */
    ;                                                                            /*increment the index                                                                  */
  
  return pcStr[i] - pcCt[i];

}/*End ms_ncompare */

  
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




