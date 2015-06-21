/*Giorgos Xatzipantelis
  AM:2489
  Assignment3-File:testsymtab.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"


void pfApply(const char *pcKey,void *pvValue,void *pvExtra);

int main(void)
{
  SymTable_T s = NULL ;
  int choice;
  char *key, *value;
  char k[] = "dasd";
  printf("\nInitializing Symbol Table..\n");
  s = SymTable_new();
  printf("..Symbol Table has been initialized !\n\nTry to apply some modifications on it..\n\nAvailable choices:\n");
  do {
    printf("\n1.Free all the allocated memory \n2.Get the number of bindings\n3.Put a new binding\n4.Remove a binding\n");
    printf("5.Search if there is a binding with a specific key\n6.Get the value of a binding given the key\n");
    printf("7.Apply the function on all the bindings\n8.Exit\n");
    printf("\nType your choice.. : ");
    scanf("%d",&choice);
    
    key = (char *)malloc(50*sizeof(char));
    value = (char *)malloc(50*sizeof(char));
        
    switch (choice) {
      case 1:
        SymTable_free(s);
        s = NULL;
        break;
      case 2:
        printf("\nThis Symbol Table has %d bindings..\n",SymTable_getLength(s));
        break;
      case 3:
        printf("Give the key of the binding : ");
        scanf("%s",key);
        printf("Give a value to this key..");
        scanf("%s",value);
        
        printf("%s\n",SymTable_put(s,key,value) ? "\nBinding succesfuly inserted ..\n" : "\nError :This key already\
 exists!!\n");
        break;
      case 4:
        printf("Give the key of the binding : ");
        scanf("%s",key);
        printf("%s\n",SymTable_remove(s,key) ? "\nBinding succesfuly removed ..\n" : "\nError :This key does not\
 exist!!\n");
        break;
      case 5:
        printf("Give the key of the binding : ");
        scanf("%s",key);
        printf("%s\n",SymTable_contains(s,key) ? "\nBinding found !! ..\n" : "\nThere is not a binding \
        with such a key..\n");
        break;
      case 6:
        printf("Give the key of the binding : ");
        scanf("%s",key);
        if ( SymTable_get(s,key) == NULL ) printf("\nThere is not such a binding..\n");
        else   printf("\nThe value of the binding with this key is : %s\n",(char *)SymTable_get(s,key));
        break;
      case 7:
        printf("\npfApply function has been applied on all the bindings of the table..\n");
        SymTable_map(s,pfApply,(char *)k);
        break;
    }
    
    
  }while ( choice != 8);
  return 0;







}/*End of Main*/


void pfApply(const char *pcKey, void *pvValue, void *pvExtra) 
{
  printf("key : %s ----> value : %s\n",pcKey,(char *)pvValue); 
}/*End of pfApply */
