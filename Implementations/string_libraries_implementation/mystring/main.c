/*Giorgos Xatzipantelis
  AM:2489
  main.c              */


#include "mystring.h"

int main(void){
  /*holding memory dynamically */ 
  char *s1 = (char *)malloc(100*sizeof(char));
  char *s2 = (char *)malloc(100*sizeof(char));
  char *cp = (char *)malloc(100*sizeof(char));
  /*asking from the user to give us all the things we need to call functions */
  printf("Give the string :");
  gets(s1);
  printf("Give the string :");
  gets(s2);
  printf("\n");
  printf("Give the number n of bytes:");
  scanf("%d",&num);
  /*calling all the functions */
  printf("mystr: %d\n",ms_length(s1));
  printf("mystr: %s\n",ms_copy(s1,s2));
  printf("mystr: %s\n",ms_concat(s1,s2));
  printf("mystr: %d\n", ms_compare(s1,s2));
  printf("mystr: %s\n", ms_search(s1,s2));
  printf("mystr: %s\n", ms_ncopy(s1,s2,num));  
  printf("mystr: %s\n", ms_nconcat(s1,s2,num));
  printf("mystr: %d\n", ms_ncompare(s1,s2,num));
  /*freeing the dynamically holded memory */ 
  free(s1);
  free(s2);
  free(cp);

  return 0;
  

}
