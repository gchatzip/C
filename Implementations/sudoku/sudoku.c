/* Giorgos Xatzipantelis
   AM:2489
   FileName:sudoku.c
   Assignment4        */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "sudoku.h"
#include "grid.h"


/* All functions that have static storage class selected is just because they are not part of the interface */

static int  check_row_conflicts(Grid_T g);
static int  check_col_conflicts(Grid_T g);
static int  check_sub_grid_conflicts(Grid_T g);
static void sudoku_init_choices(Grid_T *g); 
static int  sudoku_try_next(Grid_T g,int *row,int *col);
static int  sudoku_update_choice(Grid_T *g,int i,int j,int n);
static Grid_T sudoku_generate_complete(void);







/*Searches for conflicts in all rows .. */
static int check_row_conflicts(Grid_T g)
{
  int i,j,k,ii,flag,compare,correct;
  k=0;
  j=0;
  i=0;
  ii=0;
  flag=0;
  correct=0;
  compare=g.elts[i][j].val;
  while (k<9)
  {
    for (i=0;i<9;i++)
    {
      if (g.elts[i][j].val==compare)
      {
        flag++;/* occurance found */
        if (flag>1)/*first same occurance will be with self ! */
	{
	  printf("Row error at %d %d \n",i,j);
          correct=1;
        }
        else if (flag==1 && ii==0) /*element 0 wont be occured with itself */
	{
          printf("Row error at %d %d \n",i,j);
          correct=1;
        }       
      }/*End IF */
      k++;
      j++;
      ii++;
      compare=g.elts[ii][j].val;/*assign next value to it */
    }/*End for */
  }/*End while */
  if (correct==0){
    return 1;
  }
  else if (correct==1){
    return 0;
  }
}/*End of check_row_conflicts */

/*Searches for conflicts in all col .. */
static int check_col_conflicts(Grid_T g)
{
  int i,j,k,jj,flag,compare,correct;
  k=0;
  i=0;
  j=0;
  jj=0;
  flag=0;
  correct=0;
  compare=g.elts[i][j].val;
  while (k<9)
  {
    for (j=0;j<9;j++)
    {
      if (g.elts[i][j].val==g.elts[k][j].val)
      {
        flag++;/* occurance found */
        if (flag>1)/*first same occurance will be with self ! */
	{
	  printf("Row error at %d %d \n",i,j);
          correct=1;
        }
        else if (flag==1 && jj==0) /*element 0 wont be occured with itself */
	{
          printf("Row error at %d %d \n",i,j);
          correct=1;
        }       
      }/*End IF */
      k++;
      i++;
      jj++;
      compare=g.elts[i][jj].val;/*assign next value to it */
    }/*End for */
  }/*End while */
  if (correct==0){
    return 1;
  }
  else if (correct==1){
    return 0;
  }
}/*End of check_col_conflicts */

/*Checks for conflicts in Subgrids */
static void check_sub_grid_conflicts(Grid_T g)
{
  int i,j,k,ii,jj,compare,correct;
  k=0;
  ii=0;
  jj=0;
  correct=0;
  compare=g.elts[0][0].val;
  /* subgrid 0 */
  while(k<9){
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        if(compare==g.elts[i][j].val)
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
  /* subgrid 1 */
  compare=g.elts[0][3].val;
  while(k<9){
    for(i=0;i<3;i++){
      for(j=3;j<6;j++){
        if(compare=g.elts[i][j].val)
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */ 
  /* subgrid 2 */
  compare=g.elts[0][6].val;
  while(k<9){
    for(i=0;i<3;i++){
      for(j=6;j<9;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
  /* subgrid 3 */
  compare=g.elts[3][0].val;
  while(k<9){
    for(i=3;i<6;i++){
      for(j=0;j<3;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
   /* subgrid 4 */
  compare=g.elts[3][3].val;
  while(k<9){
    for(i=3;i<6;i++){
      for(j=3;j<6;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
   /* subgrid 5 */
  compare=g.elts[3][6].val;
  while(k<9){
    for(i=3;i<6;i++){
      for(j=6;j<9;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
   /* subgrid 6 */
  compare=g.elts[6][0].val;
  while(k<9){
    for(i=6;i<9;i++){
      for(j=0;j<3;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
   /* subgrid 7 */
  compare=g.elts[6][3].val;
  while(k<9){
    for(i=6;i<9;i++){
      for(j=3;j<6;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
   /* subgrid 8 */
  compare=g.elts[6][9].val;
  while(k<9){
    for(i=6;i<9;i++){
      for(j=6;j<9;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
  if (correct==0){
    return 1;
  }
  else if (correct==1){
    return 0;
  }
}/*End of check_sub_grid_conflicts */

/*Takes as input a puzzle and changes it in accordance to fill in the input object the possible choices that exist for every 
  place of the puzzle depending on the already included values of puzzle                                                  */
static void sudoku_init_choices(Grid_T *g)
{
  int i,j,k;

	for(i = 0; i < 9; ++i){
		for(j = 0; j < 9; ++j){
		        if(g->elts[i][j].val == 0){ /* empty cell */
				grid_clear_count(g,i,j);
				for(k = 1; k < 10; ++k){
					if(check(*g,i,j,k) == NO_ERROR){
						grid_set_choice(g,i,j,k-1);
						g->elts[i][j].choices.count++;
					}else	grid_clear_choice(g,i,j,k-1);
					
				}/*End k for */
			}
		}/*End j for */
	}/*End i for */
	for(i = 0; i < 9; ++i){
		for(j = 0; j < 9; ++j){
			if(g->elts[i][j].choices.count == 1){
				for(k = 0; k < 9; ++k){
					if(g->elts[i][j].choices.num[k] == 1){
						sudoku_eliminate_choice(g,i,j,k);
						break;
					}
				}/*End k for */
			}
		}/*End j for */
	}/*End i for */
}/*End of sudoku_init_choices*/


/*Takes a puzzle as input and examines the various choices that exist and if there is
  a unique or more unique choices returns someone of them or else returns some other choice */
static int sudoku_try_next(Grid_T g,int *row,int *col)
{
       int k, l, m, counter, most = -1;
	
	for (k = 0; k < 9; k++){
		for (l = 0; l < 9; l++){
			if(grid_read_value(sudoku,k,l) != 0) {
				continue;
			}
                        else{ /*value is zero */
			
				counter = 0;
				for (m = 0; m < 9; m++) 
					if (grid_choice_is_valid(sudoku,k,l,m) == 0)
						counter++; /*counter will say how many values the zero element can take */

				if (counter > most)
				{
					*i = k;
					*j = l;
					most = counter;
				}
			}/*End else */
		}/*End l for */
	}/*End k for */
	
	while (grid_choice_is_valid(sudoku,*i,*j,k = (rand() % 9)) == 0){
		;
	}
	return k+1;

}/*End of sudoku_try_next*/

/*Takes as input a Grid_T object and changes so it will subverse from the i,j element the choice n
  and returns the number of choices that existed for element i,j */
static int sudoku_update_choice(Grid_T *g,int i,int j,int n)
{
  g->elts[i][j].choices.num[n]=0; /* subverses the choice n from element i,j */
  return g->elts[i][j].choices.count; /*returns the count */
}/*End of sudoku_update_choice */


/*Deletes from the row r col c and the subgrid choice n */
static void sudoku_eliminate_choice(Grid_T *g,int r,int c,int n)
{
  int k,m;
   
  for(k=0;k<9;k++){
      
    if (k!=r){ /*eliminate row */
      grid_remove_choice(g,k,c,n);
    }
    if (k!=c){ /* eliminate col */
      grid_remove_choice(g,r,k,n);
    }
  }/*End k for */  
  /* eliminate subgrid */
  for(k=((r/3)*3);k>((int)(r/3)*3+2);k++){ /*this calculations allow us to find the lower and uper bounds of loop whatever the i,j is */
    for(m=((c/3)*3);m>((int)(c/3)*3+2);m++){ /*we have the int part of the diversion between the 2 numbers since they are integers */
       if ((k!=r)||(k!=c)){
	 grid_remove_choice(g,r,c,n);
       }
    }/*End m for */	   
  }/*End k for */
}/*End of sudoku_eliminate choice */












/*Searches for conflicts in all rows .. */
static int check_row_conflicts(Grid_T g)
{
  int i,j,k,ii,flag,compare,correct;
  k=0;
  j=0;
  i=0;
  ii=0;
  flag=0;
  correct=0;
  compare=g.elts[i][j].val;
  while (k<9)
  {
    for (i=0;i<9;i++)
    {
      if (g.elts[i][j].val==compare)
      {
        flag++;/* occurance found */
        if (flag>1)/*first same occurance will be with self ! */
	{
	  printf("Row error at %d %d \n",i,j);
          correct=1;
        }
        else if (flag==1 && ii==0) /*element 0 wont be occured with itself */
	{
          printf("Row error at %d %d \n",i,j);
          correct=1;
        }       
      }/*End IF */
      k++;
      j++;
      ii++;
      compare=g.elts[ii][j].val;/*assign next value to it */
    }/*End for */
  }/*End while */
  if (correct==0){
    return 1;
  }
  else if (correct==1){
    return 0;
  }
}/*End of check_row_conflicts */

/*Searches for conflicts in all col .. */
static int check_col_conflicts(Grid_T g)
{
  int i,j,k,jj,flag,compare,correct;
  k=0;
  i=0;
  j=0;
  jj=0;
  flag=0;
  correct=0;
  compare=g.elts[i][j].val;
  while (k<9)
  {
    for (j=0;j<9;j++)
    {
      if (g.elts[i][j].val==g.elts[k][j].val)
      {
        flag++;/* occurance found */
        if (flag>1)/*first same occurance will be with self ! */
	{
	  printf("Row error at %d %d \n",i,j);
          correct=1;
        }
        else if (flag==1 && jj==0) /*element 0 wont be occured with itself */
	{
          printf("Row error at %d %d \n",i,j);
          correct=1;
        }       
      }/*End IF */
      k++;
      i++;
      jj++;
      compare=g.elts[i][jj].val;/*assign next value to it */
    }/*End for */
  }/*End while */
  if (correct==0){
    return 1;
  }
  else if (correct==1){
    return 0;
  }
}/*End of check_col_conflicts */

/*Checks for conflicts in Subgrids */
static void check_sub_grid_conflicts(Grid_T g)
{
  int i,j,k,ii,jj,compare,correct;
  k=0;
  ii=0;
  jj=0;
  correct=0;
  compare=g.elts[0][0].val;
  /* subgrid 0 */
  while(k<9){
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        if(compare==g.elts[i][j].val)
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
  /* subgrid 1 */
  compare=g.elts[0][3].val;
  while(k<9){
    for(i=0;i<3;i++){
      for(j=3;j<6;j++){
        if(compare=g.elts[i][j].val)
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */ 
  /* subgrid 2 */
  compare=g.elts[0][6].val;
  while(k<9){
    for(i=0;i<3;i++){
      for(j=6;j<9;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
  /* subgrid 3 */
  compare=g.elts[3][0].val;
  while(k<9){
    for(i=3;i<6;i++){
      for(j=0;j<3;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
   /* subgrid 4 */
  compare=g.elts[3][3].val;
  while(k<9){
    for(i=3;i<6;i++){
      for(j=3;j<6;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
   /* subgrid 5 */
  compare=g.elts[3][6].val;
  while(k<9){
    for(i=3;i<6;i++){
      for(j=6;j<9;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
   /* subgrid 6 */
  compare=g.elts[6][0].val;
  while(k<9){
    for(i=6;i<9;i++){
      for(j=0;j<3;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
   /* subgrid 7 */
  compare=g.elts[6][3].val;
  while(k<9){
    for(i=6;i<9;i++){
      for(j=3;j<6;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
   /* subgrid 8 */
  compare=g.elts[6][9].val;
  while(k<9){
    for(i=6;i<9;i++){
      for(j=6;j<9;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
  if (correct==0){
    return 1;
  }
  else if (correct==1){
    return 0;
  }
}/*End of check_sub_grid_conflicts */

/*Takes as input a puzzle and changes it in accordance to fill in the input object the possible choices that exist for every 
  place of the puzzle depending on the already included values of puzzle                                                  */
static void sudoku_init_choices(Grid_T *g)
{
  int i,j,k;

	for(i = 0; i < 9; ++i){
		for(j = 0; j < 9; ++j){
		        if(g->elts[i][j].val == 0){ /* empty cell */
				grid_clear_count(g,i,j);
				for(k = 1; k < 10; ++k){
					if(check(*g,i,j,k) == NO_ERROR){
						grid_set_choice(g,i,j,k-1);
						g->elts[i][j].choices.count++;
					}else	grid_clear_choice(g,i,j,k-1);
					
				}/*End k for */
			}
		}/*End j for */
	}/*End i for */
	for(i = 0; i < 9; ++i){
		for(j = 0; j < 9; ++j){
			if(g->elts[i][j].choices.count == 1){
				for(k = 0; k < 9; ++k){
					if(g->elts[i][j].choices.num[k] == 1){
						sudoku_eliminate_choice(g,i,j,k);
						break;
					}
				}/*End k for */
			}
		}/*End j for */
	}/*End i for */
}/*End of sudoku_init_choices*/


/*Takes a puzzle as input and examines the various choices that exist and if there is
  a unique or more unique choices returns someone of them or else returns some other choice */
static int sudoku_try_next(Grid_T g,int *row,int *col)
{
       int k, l, m, counter, most = -1;
	
	for (k = 0; k < 9; k++){
		for (l = 0; l < 9; l++){
			if(grid_read_value(sudoku,k,l) != 0) {
				continue;
			}
                        else{ /*value is zero */
			
				counter = 0;
				for (m = 0; m < 9; m++) 
					if (grid_choice_is_valid(sudoku,k,l,m) == 0)
						counter++; /*counter will say how many values the zero element can take */

				if (counter > most)
				{
					*i = k;
					*j = l;
					most = counter;
				}
			}/*End else */
		}/*End l for */
	}/*End k for */
	
	while (grid_choice_is_valid(sudoku,*i,*j,k = (rand() % 9)) == 0){
		;
	}
	return k+1;

}/*End of sudoku_try_next*/

/*Takes as input a Grid_T object and changes so it will subverse from the i,j element the choice n
  and returns the number of choices that existed for element i,j */
static int sudoku_update_choice(Grid_T *g,int i,int j,int n)
{
  g->elts[i][j].choices.num[n]=0; /* subverses the choice n from element i,j */
  return g->elts[i][j].choices.count; /*returns the count */
}/*End of sudoku_update_choice */


/*Deletes from the row r col c and the subgrid choice n */
static void sudoku_eliminate_choice(Grid_T *g,int r,int c,int n)
{
  int k,m;
   
  for(k=0;k<9;k++){
      
    if (k!=r){ /*eliminate row */
      grid_remove_choice(g,k,c,n);
    }
    if (k!=c){ /* eliminate col */
      grid_remove_choice(g,r,k,n);
    }
  }/*End k for */  
  /* eliminate subgrid */
  for(k=((r/3)*3);k>(((r/3)*3+2);k++){ /*this calculations allow us to find the lower and uper bounds of loop whatever the i,j is */
    for(m=((c/3)*3);m>(((c/3)*3+2);m++){ /*we have the int part of the diversion between the 2 numbers since they are integers */
       if ((k!=r)||(k!=c)){
	 grid_remove_choice(g,r,c,n);
       }
    }/*End m for */	   
  }/*End k for */
}/*End of sudoku_eliminate choice */




/* Read a sudoku grid from stdin and return an object Grid_T
   initialized to these values. The input has the format:

1 2 3 4 5 6 7 8 9 
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 3 4 5 6 7 8 9 1 
5 6 7 8 9 1 2 3 4
8 9 1 2 3 4 5 6 7 
3 4 5 6 7 8 9 1 2
6 7 8 9 1 2 3 4 5 
9 1 2 3 4 5 6 7 8 

   Each number is followed by a space. Each line is terminated with
   \n. Values of 0 indicate empty grid cells.
*/
Grid_T sudoku_read(void)
{
  char c;
  Grid_T g;
  int i,j,k;
  
  while ((c=getchar())!=EOF){
    for (i=0;i<9;i++){
      for (j=0;j<9;j++){
	if (c!='32'&&c!='\n'){ /*is digit */
	  grid_update_value(&g,i,j,c); /*set the value of element i,j to readed one */
          grid_set_choice(&g,i,j,c);   /*set choice */
          grid_clear_count(&g,i,j);  /*clear count as the element i,j value is decided..*/
        }/*End if */
        else if( c=='\n'){
          continue;
        }
        else
          continue;                 
      }/*End j for */
    }/*End i for */
  }/*End of while */
}/*End of sudoku_read */


/* Print the sudoku puzzle defined by g to stream s in the same format
   as expected by sudoku_read(). */
void sudoku_print(FILE *s, Grid_T g)
{
	int i,j;
	
	for(i = 0; i < 9; ++i)
	{
		for(j = 0; j < 9; ++j)
		{
			fprintf(s,"%d ",g.elts[i][j].val);
		}/*End j for */
		fprintf(s,"\n");
	}/*End i for */

}/*End of sudoku_print */

/* Print all row, col, sub-grid errors/conflicts found in puzzle g;
   some errors may be reported more than once. */
void sudoku_print_errors(Grid_T g)
{
  /*implementation is by calling each checking diffently so if there is some error we get it printed */
  check_row_conflicts(g);
  check_col_conflicts(g);
  check_sub_grid_conflicts(g);

}/*End of sudoku_print_erros*/

/* Return true iff puzzle g is correct. */
int sudoku_is_correct(Grid_T g)
{
  if ((check_row_conflicts(g)==1) && (check_col_conflicts(g)==1) && (check_sub_grid_conflicts(g)==1)){
    return TRUE;
  }
  else 
    return FALSE;
}/*End of sudoku_is_correct*/



/*
* sovle puzzle g and return the solved puzzle
* if the puzzle has multiple solutions return one of the possible solutions
*/
Grid_T sudoku_solve(Grid_T g){
  Grid_T tmp_g, sol;
  int i, j;
  int n;
  int nchoice;
  while ((n = sudoku_try_next_rand(g, &i, &j))) { 
    nchoice = sudoku_remove_choice(&g, i, j, n);
    if (nchoice == 1) {
      sudoku_apply_choice(&g, i, j, n);
      sudoku_eliminate_choice(&g, i, j, n);
    } else {
      grid_clear_unique(&g);
      tmp_g = g;
      sudoku_apply_choice(&tmp_g, i, j, n);
      sol = sudoku_solve(tmp_g); /*recursion part */
      if (sudoku_is_correct(sol))
        return sol;
    }
  }
  return g;
}/*End of sudoku solve */








/*Searches for conflicts in all rows .. */
static int check_row_conflicts(Grid_T g)
{
  int i,j,k,ii,flag,compare,correct;
  k=0;
  j=0;
  i=0;
  ii=0;
  flag=0;
  correct=0;
  compare=g.elts[i][j].val;
  while (k<9)
  {
    for (i=0;i<9;i++)
    {
      if (g.elts[i][j].val==compare)
      {
        flag++;/* occurance found */
        if (flag>1)/*first same occurance will be with self ! */
	{
	  printf("Row error at %d %d \n",i,j);
          correct=1;
        }
        else if (flag==1 && ii==0) /*element 0 wont be occured with itself */
	{
          printf("Row error at %d %d \n",i,j);
          correct=1;
        }       
      }/*End IF */
      k++;
      j++;
      ii++;
      compare=g.elts[ii][j].val;/*assign next value to it */
    }/*End for */
  }/*End while */
  if (correct==0){
    return 1;
  }
  else if (correct==1){
    return 0;
  }
}/*End of check_row_conflicts */

/*Searches for conflicts in all col .. */
static int check_col_conflicts(Grid_T g)
{
  int i,j,k,jj,flag,compare,correct;
  k=0;
  i=0;
  j=0;
  jj=0;
  flag=0;
  correct=0;
  compare=g.elts[i][j].val;
  while (k<9)
  {
    for (j=0;j<9;j++)
    {
      if (g.elts[i][j].val==g.elts[k][j].val)
      {
        flag++;/* occurance found */
        if (flag>1)/*first same occurance will be with self ! */
	{
	  printf("Row error at %d %d \n",i,j);
          correct=1;
        }
        else if (flag==1 && jj==0) /*element 0 wont be occured with itself */
	{
          printf("Row error at %d %d \n",i,j);
          correct=1;
        }       
      }/*End IF */
      k++;
      i++;
      jj++;
      compare=g.elts[i][jj].val;/*assign next value to it */
    }/*End for */
  }/*End while */
  if (correct==0){
    return 1;
  }
  else if (correct==1){
    return 0;
  }
}/*End of check_col_conflicts */

/*Checks for conflicts in Subgrids */
static void check_sub_grid_conflicts(Grid_T g)
{
  int i,j,k,ii,jj,compare,correct;
  k=0;
  ii=0;
  jj=0;
  correct=0;
  compare=g.elts[0][0].val;
  /* subgrid 0 */
  while(k<9){
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        if(compare==g.elts[i][j].val)
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
  /* subgrid 1 */
  compare=g.elts[0][3].val;
  while(k<9){
    for(i=0;i<3;i++){
      for(j=3;j<6;j++){
        if(compare=g.elts[i][j].val)
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */ 
  /* subgrid 2 */
  compare=g.elts[0][6].val;
  while(k<9){
    for(i=0;i<3;i++){
      for(j=6;j<9;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
  /* subgrid 3 */
  compare=g.elts[3][0].val;
  while(k<9){
    for(i=3;i<6;i++){
      for(j=0;j<3;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
   /* subgrid 4 */
  compare=g.elts[3][3].val;
  while(k<9){
    for(i=3;i<6;i++){
      for(j=3;j<6;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
   /* subgrid 5 */
  compare=g.elts[3][6].val;
  while(k<9){
    for(i=3;i<6;i++){
      for(j=6;j<9;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
   /* subgrid 6 */
  compare=g.elts[6][0].val;
  while(k<9){
    for(i=6;i<9;i++){
      for(j=0;j<3;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
   /* subgrid 7 */
  compare=g.elts[6][3].val;
  while(k<9){
    for(i=6;i<9;i++){
      for(j=3;j<6;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
   /* subgrid 8 */
  compare=g.elts[6][9].val;
  while(k<9){
    for(i=6;i<9;i++){
      for(j=6;j<9;j++){
        if(g.elts[ii][jj]==g.elts[i][j])
	{
          printf("Error at: %d,%d \n",i,j);
          correct=1;
        }/*End if */
      }/*End j for*/
    }/*End i for*/
    ii++;
    jj++;
    k++;
    compare=g.elts[ii][jj].val; /*assign the next value*/
  }/*End while */
  if (correct==0){
    return 1;
  }
  else if (correct==1){
    return 0;
  }
}/*End of check_sub_grid_conflicts */

/*Takes as input a puzzle and changes it in accordance to fill in the input object the possible choices that exist for every 
  place of the puzzle depending on the already included values of puzzle                                                  */
static void sudoku_init_choices(Grid_T *g)
{
  int i,j,k;

	for(i = 0; i < 9; ++i){
		for(j = 0; j < 9; ++j){
		        if(g->elts[i][j].val == 0){ /* empty cell */
				grid_clear_count(g,i,j);
				for(k = 1; k < 10; ++k){
					if(check(*g,i,j,k) == NO_ERROR){
						grid_set_choice(g,i,j,k-1);
						g->elts[i][j].choices.count++;
					}else	grid_clear_choice(g,i,j,k-1);
					
				}/*End k for */
			}
		}/*End j for */
	}/*End i for */
	for(i = 0; i < 9; ++i){
		for(j = 0; j < 9; ++j){
			if(g->elts[i][j].choices.count == 1){
				for(k = 0; k < 9; ++k){
					if(g->elts[i][j].choices.num[k] == 1){
						sudoku_eliminate_choice(g,i,j,k);
						break;
					}
				}/*End k for */
			}
		}/*End j for */
	}/*End i for */
}/*End of sudoku_init_choices*/


/*Takes a puzzle as input and examines the various choices that exist and if there is
  a unique or more unique choices returns someone of them or else returns some other choice */
static int sudoku_try_next(Grid_T g,int *row,int *col)
{
       int k, l, m, counter, most = -1;
	
	for (k = 0; k < 9; k++){
		for (l = 0; l < 9; l++){
			if(grid_read_value(sudoku,k,l) != 0) {
				continue;
			}
                        else{ /*value is zero */
			
				counter = 0;
				for (m = 0; m < 9; m++) 
					if (grid_choice_is_valid(sudoku,k,l,m) == 0)
						counter++; /*counter will say how many values the zero element can take */

				if (counter > most)
				{
					*i = k;
					*j = l;
					most = counter;
				}
			}/*End else */
		}/*End l for */
	}/*End k for */
	
	while (grid_choice_is_valid(sudoku,*i,*j,k = (rand() % 9)) == 0){
		;
	}
	return k+1;

}/*End of sudoku_try_next*/

/*Takes as input a Grid_T object and changes so it will subverse from the i,j element the choice n
  and returns the number of choices that existed for element i,j */
static int sudoku_update_choice(Grid_T *g,int i,int j,int n)
{
  g->elts[i][j].choices.num[n]=0; /* subverses the choice n from element i,j */
  return g->elts[i][j].choices.count; /*returns the count */
}/*End of sudoku_update_choice */


/*Deletes from the row r col c and the subgrid choice n */
static void sudoku_eliminate_choice(Grid_T *g,int r,int c,int n)
{
  int k,m;
   
  for(k=0;k<9;k++){
      
    if (k!=r){ /*eliminate row */
      grid_remove_choice(g,k,c,n);
    }
    if (k!=c){ /* eliminate col */
      grid_remove_choice(g,r,k,n);
    }
  }/*End k for */  
  /* eliminate subgrid */
  for(k=((r/3)*3);k>((int)(r/3)*3+2);k++){ /*this calculations allow us to find the lower and uper bounds of loop whatever the i,j is */
    for(m=((c/3)*3);m>((int)(c/3)*3+2);m++){ /*we have the int part of the diversion between the 2 numbers since they are integers */
       if ((k!=r)||(k!=c)){
	 grid_remove_choice(g,r,c,n);
       }
    }/*End m for */	   
  }/*End k for */
}/*End of sudoku_eliminate choice */


	/*generates all the possible choices for each place (_init_choices
         *uses try_next to replace one to one the 0 of the initial puzzle with the correct values 
         *its not insured that generate_complete will retrun a correct puzzle .. */
static Grid_T sudoku_generate_complete(void){

	Grid_T g;
	int i,j,v;
	
	grid_clear_unique(&g);
	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++)
		{
			grid_update_value(&g,i,j,0);
		}
	}
	sudoku_init_choices(&g);
	
	while(sudoku_is_full(g) == FALSE){
		v = sudoku_try_next(g,&i,&j);
		set_cell(&g,i,j,v);
		sudoku_init_choices(&g);
	}
	
	grid_clear_unique(&g);
	
	return g;
}/*End of sudoku_generate_complete */


int main(int argc,char **argv)
{
	Grid_T sudoku,s;

	srand(getpid());
	

	if(argc == 4 && strcmp(argv[1],"-g") == 0 && strcmp(argv[3],"-u") == 0)
	{
		sudoku = sudoku_generate(atoi(argv[2]),UNIQUE);
		printf("New puzzle:\n");
		sudoku_print(stdout,sudoku);
	}
	else if(argc == 3 && strcmp(argv[1],"-g") == 0)
	{
		sudoku = sudoku_generate(atoi(argv[2]),UNIQUE-1);
		printf("New puzzle:\n");
		sudoku_print(stdout,sudoku);
	}
	
	sudoku_init_choices(&sudoku);
	
	while(sudoku_is_full(s = sudoku_solve(sudoku)) == FALSE){
		s = sudoku;
	}

	printf("%s\n",grid_read_unique(sudoku) == 1 ? "Puzzle has a (unique choice) solution:" : "Puzzle has multiples solutions:");
	
	sudoku_print(stdout,s);
	
	if(sudoku_is_correct(s) == TRUE){
		printf("Puzzle solution is correct\n");
	}else{
		printf("Puzzle solution is wrong\n");
	}

	return 0;
}
