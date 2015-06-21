/*Giorgos Xatzipantelis
  AM:2489
  Assignment3-File:symtable.h */


/*This is the symtable.h Abstract Data Type (ADT)*/
/*Every instance of this ADT will be a symbol table*/
/*This is a general type ADT with the meaning that it is 
designed to be general with void * type for values so that 
we achive polymorphism and buy the ability to be able to use with
any type of data.*/

typedef struct SymTable *SymTable_T;


/*Returns a new SymTable_T that is empty(no bindings in it)*/
SymTable_T SymTable_new(void);

/*SymTable_free has to free all memory used from oSymTable*/
/*If oSymTable==NULL then the function must do nothing    */
void SymTable_free(SymTable_T oSymTable);

/*Returns numer of bindings included in oSymTable*/
/*It is a checked runtime error for oSymTable to be NULL*/
unsigned int SymTable_getLength(SymTable_T oSymtable);

/*If binding with key pcKey not included in oSymTable then                      */
/*SymTable_put has to put a new binding to oSymTable that will be apparted from */
/*key:pcKey and value pvValue                                                   */
/*Returns:1(TRUE)                                                               */
/*Differently SymTable_put has not to change oSymTable and                      */
/*Return:0(FALSE)                                                               */
/*It is a checked runtime error for oSymTable or pcKey to be NULL               */
int SymTable_put(SymTable_T oSymTable,const char * pcKey,const void *pvValue);

/*If binding with key pcKey included in oSymTable then
  SymTable_remove has to :
  Remove the binding from oSymTable and Return:1(TRUE)
  Else SymTable has not to change oSymTable and has to Return:0(FALSE)
  It is a checked runtime error for oSymTable or pcKey to be NULL               */
int SymTable_remove(SymTable_T oSymTable,const char *pcKey);

/*SymTable_contains has to :
  Return:1(TRUE) if oSymTable includes a binding witch key is pcKey
  Differently it has to Return:0(FALSE)
  It is a checked runtime error for oSymTable or pcKey to be NULL                */
int SymTable_contains(SymTable_T oSymTable,const char *pcKey);


/*SymTable_get has to :
  Return the value of binding to oSymTable witch key is pcKey
  or Return NULL if such a key does not exist
  It is a checked runtime error for oSymTable or pcKey to be NULL                */
void *SymTable_get(SymTable_T oSymTable,const char *pcKey);


/*SymTable_map has to apply the function *pfApply to every binding include in oSymTable
  passing pvExtra as extra argument.
  It is a checked runtime error for oSymTable or pfApply to be NULL              */
void SymTable_map(SymTable_T oSymTable,
                         
		  void (*pfApply)(const char *pcKey,void *pvValue,void *pvExtra),
                  
                  const void *pvExtra);
