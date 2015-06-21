

#define TRUE 1
#define FALSE 0
#define ROW_ERROR 1
#define COL_ERROR 2
#define SUBG_ERROR 3
#define NO_ERROR 0
#define UNIQUE 1

/*the structure definition for the puzzle*/
typedef struct grid_s
{
	int unique;
	struct { 
		int val;       /* value of element i,j */
		struct {         
			int count;   /* number of possible choices for element i,j */ 
			int num[9]; /* map of choices: num[k]==1 if k is a valid choice for element i,j, else num[k]=0 */
		} choices;     /* struct choices is used while solving the puzzle and is otherwise undefined */
	} elts[9][9];    /* sudoku grid elements; 0<=i,j<=9 */
}Grid_T;

/*update a cell*/
int set_cell(Grid_T *g, int i, int j, int value);

/*fills the cells with unique choices*/
int add_cells(Grid_T *g);

/*finds the cells with unique choices*/
int find_cells(Grid_T *g);

/*finds the cells with unique choices in the rows*/
int find_rows(Grid_T *g);

/*finds the cells with unique choices in the columns*/
int find_columns(Grid_T *g);

/*finds the cells with unique choices in the sub_grids*/
int find_grids(Grid_T *g);

/*check if a value can pe put in a cell*/
int check(Grid_T g,int row, int column, int value);

/* update value of i,j to n */
void grid_update_value(Grid_T *g, int i, int j, int n);

/* return value of i,j */
int grid_read_value(Grid_T g, int i, int j);

/* set (to 1) or clear (to 0) choice n for elt i,j */
void grid_set_choice(Grid_T *g, int i, int j, int n);
void grid_clear_choice(Grid_T *g, int i, int j, int n);

/* true if choice n for elt i,j is valid */
int grid_choice_is_valid(Grid_T g, int i, int j, int n);

/* remove n from choices of elt i,j and adjust count only if n is a
   valid choice for elt i,j */
void grid_remove_choice(Grid_T *g, int i, int j, int n);

/* return count, set (to 9), or clear (to 0) count for elt i, j */
int grid_read_count(Grid_T g, int i, int j);
void grid_set_count(Grid_T *g, int i, int j);
void grid_clear_count(Grid_T *g, int i, int j);

/* return val, set (to 1), or clear (to 0) unique flag for g */
int grid_read_unique(Grid_T g);
void grid_set_unique(Grid_T *g);
void grid_clear_unique(Grid_T *g);

/*check if the puzzle is full*/
int sudoku_is_full(Grid_T g);
