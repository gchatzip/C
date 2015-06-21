/*Giorgos Xatzipantelis
  AM:2489
  Assignment3-File:symtablehash.c*/


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"symtable.h"

#define HASH_MULTIPLIER 65599

static unsigned int SymTable_hash(const char *pcKey);
static void SymTable_expand(SymTable_T oSymTable);


struct node {
  char *key; 
  void *value;
  struct node *next;
};
struct SymTable {
  int length;
  int maxSize;
  struct node **hash;/*hash table is a pointer to struct */
};

/*Returns a new SymTable_T that is empty(no bindings in it)*/
SymTable_T SymTable_new(void)
{
  SymTable_T Table;
  int i;

  Table=malloc(sizeof(struct SymTable));
  Table->hash=(struct node **)malloc(509*sizeof(struct node));

  Table->length=0;
  Table->maxSize=509;
  
  for(i=0;i<509;i++)      
    Table->hash[i]=NULL; /*initialize every bucket of hashTable to NULL */
  
  return Table;

}/*End of Symtable_new */


/*SymTable_free has to free all memory used from oSymTable*/
/*If oSymTable==NULL then the function must do nothing    */
void SymTable_free(SymTable_T oSymTable)
{

  struct node *hashPtr,*tempPtr;
  int i;

  if (oSymTable==NULL){
    return;/* if its NULL do nothing */
  }
  else{
    for(i=0;i<oSymTable->maxSize;i++)
      for(hashPtr=oSymTable->hash[i];hashPtr!=NULL;hashPtr=tempPtr){/*iterate throughout hashTable elements*/
	tempPtr=hashPtr->next;
        free(hashPtr->key);
        free(hashPtr);
      }
    free(oSymTable->hash);
    free(oSymTable);
  }
}/*End of SymTable_free */


/*Returns numer of bindings included in oSymTable*/
/*It is a checked runtime error for oSymTable to be NULL*/
unsigned int SymTable_getLength(SymTable_T oSymTable)
{


  assert(oSymTable);
  
  return oSymTable->length;

}/*End of SymTable_getLength*/


/*If binding with key pcKey not included in oSymTable then                      */
/*SymTable_put has to put a new binding to oSymTable that will be apparted from */
/*key:pcKey and value pvValue                                                   */
/*Returns:1(TRUE)                                                               */
/*Differently SymTable_put has not to change oSymTable and                      */
/*Return:0(FALSE)                                                               */
/*It is a checked runtime error for oSymTable or pcKey to be NULL               */
int SymTable_put(SymTable_T oSymTable,const char * pcKey,const void *pvValue)
{
 char *pcKeyCopy;
 struct node *nodePtr;
  
  assert(oSymTable);
  assert(pcKey);
  
  if (oSymTable->maxSize == oSymTable->length)
	     SymTable_expand(oSymTable);
		
  if (SymTable_contains(oSymTable,pcKey) == 1)
    return 0;
  else {

    pcKeyCopy = (char *)malloc(strlen(pcKey)*sizeof(char));
    pcKeyCopy = strcpy(pcKeyCopy,pcKey);
    
    nodePtr = (struct node *)malloc(sizeof(struct node));
    
    nodePtr->key = pcKeyCopy;
    nodePtr->value =(void *)pvValue;
    nodePtr->next = oSymTable->hash[SymTable_hash(pcKey)%oSymTable->maxSize];
    
    oSymTable->hash[SymTable_hash(pcKey)%oSymTable->maxSize] = nodePtr;
    oSymTable->length =oSymTable->length + 1;
		
    return 1;
  }
}/*End of SymTable_put */


/*If binding with key pcKey included in oSymTable then
  SymTable_remove has to :
  Remove the binding from oSymTable and Return:1(TRUE)
  Else SymTable has not to change oSymTable and has to Return:0(FALSE)
  It is a checked runtime error for oSymTable or pcKey to be NULL               */
int SymTable_remove(SymTable_T oSymTable,const char *pcKey)
{
  struct node *cur,*prev;

  assert(oSymTable);
  assert(pcKey);

  for(cur=oSymTable->hash[SymTable_hash(pcKey)%oSymTable->maxSize],prev=NULL;
      cur!=NULL;    
      cur=cur->next){
    
    if(strcmp(pcKey,cur->key)==0){

      if (prev==NULL) /*pcKey is in the first node */{
        oSymTable->hash[SymTable_hash(pcKey)%oSymTable->maxSize]=cur->next; /*bypass the pointer */
      }
      else{
        prev->next=cur->next; /*link the nodes as we should */

        free(cur->key);
        free(cur);
        
        oSymTable->length=oSymTable->length-1; /*reduce the length of SymTable */
        
        return 1;/*operation successfully exectued */
        
      }
    }

  }
  return 0;/*it was not found */
}/*End of SymTable_remove */

/*SymTable_contains has to :
  Return:1(TRUE) if oSymTable includes a binding witch key is pcKey
  Differently it has to Return:0(FALSE)
  It is a checked runtime error for oSymTable or pcKey to be NULL                */
int SymTable_contains(SymTable_T oSymTable,const char *pcKey)
{
  struct node *symPtr;
  
  assert(oSymTable);
  assert(pcKey);
 
  for ( symPtr = oSymTable->hash[SymTable_hash(pcKey)%oSymTable->maxSize];
        symPtr != NULL; 
        symPtr = symPtr->next){
    if (strcmp(pcKey,symPtr->key) == 0)
      return 1; /*successfully found */
  }
        
  return 0; /*not found */

}/*End of SymTable_contains */

/*SymTable_get has to :
  Return the value of binding to oSymTable witch key is pcKey
  or Return NULL if such a key does not exist
  It is a checked runtime error for oSymTable or pcKey to be NULL                */
void *SymTable_get(SymTable_T oSymTable,const char *pcKey)
{
  struct node *symPtr;

  assert(oSymTable);
  assert(pcKey);

  for ( symPtr = oSymTable->hash[SymTable_hash(pcKey)%oSymTable->maxSize];
        symPtr != NULL; 
        symPtr = symPtr->next){
    if (strcmp(pcKey,symPtr->key) == 0)
      return symPtr->value; /*return the value */
  }
  return NULL;

}/*End of SymTable_get */


/*SymTable_map has to apply the function *pfApply to every binding include in oSymTable
  passing pvExtra as extra argument.
  It is a checked runtime error for oSymTable or pfApply to be NULL              */
void SymTable_map(SymTable_T oSymTable,
                         
		  void (*pfApply)(const char *pcKey,void *pvValue,void *pvExtra),
                  const void *pvExtra)
{
  int i;
  struct node *symPtr;

  assert(oSymTable);
  assert(pfApply);

  for (i=0;i<oSymTable->maxSize;i++)
    for (symPtr=oSymTable->hash[i];
         symPtr!=NULL;
         symPtr=symPtr->next)

      (*pfApply)(symPtr->key,symPtr->value,(void *)pvExtra);
}/*End of SymTable_map */


/*Return a has code for pcKey*/
static unsigned int SymTable_hash(const char *pcKey)
{
  size_t ui;

  unsigned int uiHash=0U;

  for(ui=0U;pcKey[ui]!='\0';ui++)

    uiHash=uiHash*HASH_MULTIPLIER+pcKey[ui];

  return uiHash;
}/*End of SymTable_hash */

/*The expand implementation */
static void SymTable_expand(SymTable_T oSymTable)
{
	
	int i , previous;
	struct node *ptr, *tmp, **newHash;
	
	previous = oSymTable->maxSize; /*the size we had before expanding */
	
        /*here we do the bucket cheking expanding to the number requested and needed in each case */
	if (oSymTable->maxSize == 509) 
		oSymTable->maxSize = 1021;
	else if (oSymTable->maxSize == 1021)
		oSymTable->maxSize = 2053;
	else if (oSymTable->maxSize == 2053)
		oSymTable->maxSize = 4093;
	else if (oSymTable->maxSize == 4093)
		oSymTable->maxSize = 8191;
	else if (oSymTable->maxSize == 8191)
		oSymTable->maxSize = 16381;
	else if (oSymTable->maxSize == 16381)
		oSymTable->maxSize = 32771;
	else if (oSymTable->maxSize == 32771)
		oSymTable->maxSize = 65521;
	else assert(NULL);/*Stop the execution */
	
	/*allocate memory for the new pointer to array of pointers*/
	newHash = (struct node **)malloc(oSymTable->maxSize*sizeof(struct node *));
	
	/*Initialize with null the new hash table*/
	for ( i = 0; i < oSymTable->maxSize ;i++)
		newHash[i] = NULL;
		
	for ( i = 0; i < previous; i++)
		for ( ptr = oSymTable->hash[i]; ptr != NULL; ptr = ptr->next) {
			tmp = ptr ;
			tmp->next = newHash[SymTable_hash(ptr->key)%oSymTable->maxSize];
			newHash[SymTable_hash(ptr->key)%oSymTable->maxSize] = tmp;
		}
	
	free(oSymTable->hash);
	
	oSymTable->hash = newHash;
}
 
