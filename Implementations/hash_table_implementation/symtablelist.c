/*Giorgos Xatzipantelis 
  AM:2489
  Assignment3-File:symtablelist.c */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "symtable.h"

struct SymTable{
  char *key;
  void *value;
  SymTable_T next;
};

SymTable_T SymTable_new(void)
{  
  SymTable_T SymPtr=malloc(sizeof(struct SymTable));
  
  SymPtr->key=NULL;
  SymPtr->value=NULL;
  SymPtr->next=NULL;

  return SymPtr; /* returns pointer to start of allocated memory block */
}/*End of SymTable_new */

void SymTable_free(SymTable_T oSymTable)
{
  SymTable_T symPtr;
  SymTable_T tempPtr;
  if (oSymTable==NULL) /* If oSymTable==NULL then do nothing */
    return;
  else{
    for (symPtr=oSymTable->next; /*initialiazation part */
	 symPtr!=NULL; /* loop condition */
         symPtr=tempPtr) /* step */ 
    { /* for block of instructions */

       tempPtr=symPtr->next;
       free(tempPtr->key);
       free(tempPtr);
        
    }
    free(oSymTable); /*release the claimed space */
  }
  return;
}/*End of SymTable_free */


unsigned int SymTable_getLength(SymTable_T oSymTable)
{

  unsigned int length=0U;
 
  SymTable_T symPtr;
 
  assert(oSymTable); /* if oSymTable is NULL stop execution of the function */

  for(symPtr=oSymTable->next; /*initialiazation */
      symPtr!=NULL;           /*loop condition */
      symPtr=symPtr->next)  /*    step        */

    length++; /*increment the length since we have another binding */


  return length;



}/*End of SymTable_getLength */


int SymTable_put(SymTable_T oSymTable,const char *pcKey,const void *pvValue)
{
    
  SymTable_T new_node;
  char *pcKeyCopy;

  assert(oSymTable); /*stop function execution if oSymTable==NULL */
  assert(pcKey);     /*stop function execution if pcKey==NULL     */

  pcKeyCopy=malloc(strlen(pcKey)*sizeof(char));
  pcKeyCopy=strcpy(pcKeyCopy,pcKey); /*We do this because SymTable must "own" its keys.*/

  if (SymTable_getLength(oSymTable)==0){
     
    new_node=malloc(sizeof(struct SymTable));

    new_node->key=pcKeyCopy;
    new_node->value=(void *)pvValue;
    new_node->next=NULL;
   
    oSymTable->next=new_node;

    return 1; /*binding succesfully added */

  }
  else if (SymTable_contains(oSymTable,pcKey)==1) /*binding allready exists */
 
    return 0; /*binding not succesfully added */
  
  else {
  
    new_node=malloc(sizeof(struct SymTable));

    new_node->key=pcKeyCopy;
    new_node->value=(void *)pvValue;
    new_node->next=oSymTable->next;

    oSymTable->next=new_node;
   
    return 1;/*binding succesfully added */
  }

}/*End of SymTable_put */



int SymTable_remove(SymTable_T oSymTable,const char *pcKey)
{
  SymTable_T cur,prev;
 
  assert(oSymTable);/*stop execution of function if oSymTable is NULL */
  assert(pcKey);/*stop execution of function if pcKey is NULL */

  for(cur=oSymTable->next,prev=NULL; /*Initialiazation */
      cur!=NULL; /* Condition */
      prev=cur,cur=cur->next){/*Step*/
     if (strcmp(pcKey,cur->key) == 0) {

         if (prev==NULL)

           oSymTable->next=cur->next; /*pcKey was in the first node */
   
         else 
           prev->next=cur->next;  /*pcKey is in some other node */

         free(cur->key);
         free(cur);

         return 1; /*Successfully deleted the binding */
     }


  }  
  return 0;      


}/*End of SymTable_remove */

int SymTable_contains(SymTable_T oSymTable,const char *pcKey)
{
  SymTable_T symPtr;

  assert(oSymTable);
  assert(pcKey);

  for(symPtr=oSymTable->next;
      symPtr!=NULL;
      symPtr=symPtr->next){
     
    if (strcmp(pcKey,symPtr->key)==0) /*founded */
      return 1;
  }
    
  return 0; /*not founded */


}/*End of SymTable_contains */

void *SymTable_get(SymTable_T oSymTable,const char *pcKey)
{

  SymTable_T symPtr;

  assert(oSymTable);
  assert(pcKey);

  for(symPtr=oSymTable->next;
      symPtr!=NULL;
      symPtr=symPtr->next){

    if (strcmp(pcKey,symPtr->key)==0){
        
      return symPtr->value;
    }
  }
  return NULL;



}/*End of SymTable_get */

void SymTable_map(SymTable_T oSymTable,
                  void (*pfApply)(const char *pcKey,void *pvValue,void *pvExtra),
                  const void *pvExtra)
{
  SymTable_T symPtr;
  
  assert(oSymTable);
  assert(pfApply); /*Stop function execution if pfApply==NULL */

  for(symPtr=oSymTable->next;
      symPtr!=NULL;
      symPtr=symPtr->next)
    
    (*pfApply)(symPtr->key,symPtr->value,(void *)pvExtra);

  return;
     




}/*End of SymTable_map */
                            
