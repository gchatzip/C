/*     Giorgos Xatzipantelis
       AM : 2489
       FileName : grid.c
       Assignment4            */

#include <stdio.h>
#include <stdlib.h>
#include "grid.h"



/*update the value of i,j to n*/
void grid_update_value(Grid_T *g,int i,int j,int n)
{
  g->elts[i][j].val=n;

}/*End of grid_update_value */

/* return value of i,j */
int grid_read_value(Grid_T g, int i, int j)
{
  return  g.elts[i][j].val;

}/*End of grid_read_value */

/* Set (to 1)  choice n for elt i,j */
void grid_set_choice(Grid_T *g, int i, int j, int n)
{
  g->elts[i][j].choices.num[n]=1;

}/*End of grid_set_choice */

/* Clear (to 0) choice n for elt i,j */
void grid_clear_choice(Grid_T *g, int i, int j, int n)
{
  g->elts[i][j].choices.num[n]=0;

}/*End of grid_clear_choie */

/* true if choice n for elt i,j is valid */
int grid_choice_is_valid(Grid_T g, int i, int j, int n)
{
  return g.elts[i][j].choices.num[n];

}/*End of grid_choice_is_valid */

/* remove n from choices of elt i,j and adjust count only if n is a
   valid choice for elt i,j */
void grid_remove_choice(Grid_T *g, int i, int j, int n)
{
  
  if ( grid_choice_is_valid( *g, i, j, n)==TRUE )
  {
    g->elts[i][j].choices.count--;
    g->elts[i][j].choices.num[n] = 0;
  }

}/*End of grid_remove_choice */


/* return count  */
int grid_read_count(Grid_T g, int i, int j)
{
  return g.elts[i][j].choices.count;

}/*End of grid_read_count */


/*set (to 9) count for elt i,j */
void grid_set_count(Grid_T *g, int i, int j)
{
  g->elts[i][j].choices.count = 9;
  
}/*End of grid_set_count */

/*clear (to 0) count for elt i,j */
void grid_clear_count(Grid_T *g, int i, int j)
{
  g->elts[i][j].choices.count = 0;

}/*End of grid_clear_count*/

/* return val */
int grid_read_unique(Grid_T g)
{
  return g.unique;

}/*End of grid_read_unique */

/* Set (to 1) unique flag for g */
void grid_set_unique(Grid_T *g)
{
   g->unique=1;

}/*End of grid_set_unique  */

/* Clear (to 0) unique flag for g */
void grid_clear_unique(Grid_T *g)
{
  g->unique=0;

}/* End of grid_clear_unique */


/*check if a value can pe put in a cell*/
int check(Grid_T g,int row, int column, int value) {
  int i , j;

  /*check for conflicts in a column*/
  for (i = 0; i < 9; ++i) {
    if ((g.elts[i][column].val == value) && (i != row)) {
      return COL_ERROR;
    }
  }

  /*check for conflicts in a row*/
  for (j = 0; j < 9; ++j) {
    if ((g.elts[row][j].val == value) && (j != column)) {
      return ROW_ERROR;
    }
  }
  
  /*check for conflicts in a small 3*3 square*/ 
  for (i = row - row % 3; i < row - row % 3 + 3; ++i) {
    for (j = column - column % 3; j < column - column % 3 + 3; j++) {
      if ((g.elts[i][j].val == value) && ((i != row) || (j != column))) {
        return SUBG_ERROR;
      }
    }
  }
  return NO_ERROR;
}
