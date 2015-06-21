#include <stdio.h> /* header for all c files */

int _init_(int cmap[][3]); /* initialization function that initializes the c.map table */
int sANY(int c,int cmap[][3]); /*seen any c  */
int sM(int c,int cmap[][3]);/*  have seen M  */
int sN(int c,int cmap[][3]);/*  have seen N  */
int sm(int c,int cmap[][3]);/*  have seen m  */
int sn(int c,int cmap[][3]);/*  have seen n  */


int main(void){/* responsibilities : initilize the c.map array and then call the swap states*/
               /* function that is repsonsible for chaning the states as expected */
               /* void arguments as we dont expect a cmd line argument */

  int cmap[255][3];/* 255 x 3 2-dimensional array that holds the expected behavior */
  int c; /* C language refers to chars as integers throughout the ascii value */
  /* enumeratiing the state values so we can handle as int */
  int state=0;
  /*array with pointer to the function states */
  int (*action[5])(int c,int cmap[][3]);
 

  _init_(cmap); /* calling the function to initialize the array */
  /* sANY-sM-sN-sn-sm is the functions that handle the state changement and I/O */
  action[0]=sANY;
  action[1]=sM;
  action[2]=sN;
  action[3]=sn;
  action[4]=sm;
  state=0; /* first time should start from any so we can get the states swaped */
  while ((c=getchar())!=EOF){/* looping throughtout the expected states */

    state=action[state](c,cmap);/*Will call the state functions to output as excpected */
      
  }
  return 0;
}
enum states{stANY,stN,stM,stn,stm};

int _init_(int cmap[][3]){
  /* initiliazing following the iso index of the iso8859-7 index and*/
  /* chaning all the values as described and set 0 as dont care */

  int i,j;
  for (i=0;i<256;i++){
    for(j=0;j<3;j++)
      cmap[i][j]=0;/* elements will be initialized to 0 (maybe not printable state!*/
  }
  for (i=0;i<256;i++)
    cmap[i][0]=i; /* initializing all c.map[i][0] as the character in the iso8859-7 array so that we wil only modify the expected ones */


    /*capital*/                                  /*small*/
  cmap[193][0] = 'A';                          cmap[225][0] = 'a';
  cmap[194][0] = 'V';                          cmap[226][0] = 'v';
  cmap[195][0] = 'G';                          cmap[227][0] = 'g';
  cmap[196][0] = 'D';                          cmap[228][0] = 'd';
  cmap[197][0] = 'E';                          cmap[229][0] = 'e';
  cmap[198][0] = 'Z';                          cmap[230][0] = 'z';
  cmap[199][0] = 'H';                          cmap[231][0] = 'h';
  cmap[200][0] = '8';                          cmap[232][0] = '8';
  cmap[201][0] = 'I';                          cmap[233][0] = 'i';
  cmap[202][0] = 'K';                          cmap[234][0] = 'k';
  cmap[203][0] = 'L';                          cmap[235][0] = 'l';
  cmap[204][0] = 'M';                          cmap[236][0] = 'm';
  cmap[205][0] = 'N';                          cmap[237][0] = 'n';
  cmap[206][0] = 'K'; cmap[206][1]='S';        cmap[238][0] = 'k'; cmap[238][1]='s';
  cmap[207][0] = 'O';                          cmap[239][0] = 'o';
  cmap[208][0] = 'P';                          cmap[240][0] = 'p';
  cmap[209][0] = 'R';                          cmap[241][0] = 'r';
  cmap[211][0] = 'S';                          cmap[242][0] = 's';
  cmap[212][0] = 'T';                          cmap[243][0] = 's';
  cmap[213][0] = 'Y';                          cmap[244][0] = 't';
  cmap[214][0] = 'F';                          cmap[245][0] = 'y';
  cmap[215][0] = 'C';   cmap[215][1] = 'H';    cmap[246][0] = 'f';
  cmap[216][0] = 'P';   cmap[216][1] = 'S';    cmap[247][0] = 'c';  cmap[247][1] = 'h'; 
  cmap[217][0] = 'W';                          cmap[248][0] = 'p';  cmap[248][1] = 's';
                                               cmap[249][0] = 'w'; 

    /*capital with tono*/
  cmap[182][0] = 39;   cmap[182][1] = 'A';   
  cmap[184][0] = 39;   cmap[184][1] = 'E';   
  cmap[185][0] = 39;   cmap[185][1] = 'H';   
  cmap[186][0] = 39;   cmap[186][1] = 'I';   
  cmap[188][0] = 39;   cmap[188][1] = 'O';   
  cmap[190][0] = 39;   cmap[190][1] = 'Y';   
  cmap[191][0] = 39;   cmap[191][1] = 'W';   
    
    /*small with tono*/
  cmap[220][0] = 'a';  cmap[220][1] = 39;
  cmap[221][0] = 'e';  cmap[221][1] = 39;
  cmap[222][0] = 'h';  cmap[222][1] = 39;
  cmap[223][0] = 'i';  cmap[223][1] = 39;
  cmap[252][0] = 'o';  cmap[252][1] = 39;
  cmap[253][0] = 'y';  cmap[253][1] = 39;
  cmap[254][0] = 'w';  cmap[254][1] = 39;
    
    /*small with dialytika kai tono*/
  cmap[250][0] = 'i';  cmap[250][1] = '"';   
  cmap[251][0] = 'y';  cmap[251][1] = '"';    
  cmap[192][0] = 'i';  cmap[192][1] = 39;      cmap[192][2] = '"';   
  cmap[224][0] = 'y';  cmap[224][1] = 39;      cmap[224][2] = '"';
  
    /*capital me dialytika */
  cmap[218][0] = 'I';  cmap[218][1] = '"';
  cmap[219][0] = 'Y';  cmap[219][1] = '"';
  return 0;
  
}
int sANY(int c,int cmap[][3]){/*the seen any char function that will output the char seen*/
                               /*if not M,N,n,m*/
  int state;
  if (c == 204)                     
    state =stM;                    /*Going to state M*/   
  else if (c == 205)
    state =stN;                    /*Going to state N*/
  else if (c == 236)       
    state =stm;                     /*Going to state m*/
  else if (c == 237)
    state = stn;                  /*Going to state n*/
  else {
    printf("%c%c%c",cmap[c][0], cmap[c][1], cmap[c][2]);   /*Outputting and staying in the same state*/
    state =stANY;                                                         
  }
  return state;

}/*END sANY*/


int sN(int c,int cmap[][3]) /*seen N and we implement different states depending on what char seen so we can decide what to output */
{
  int state;  

  if (c == 205) {                /*Seen again N*/
    putchar('N');
    state = stN;
  }
  else if (c == 237) {
    putchar('N');
    state = stn;
  }
  else if (c == 204) {
    putchar('N');
    state = stM;
  }
  else if (c == 236) {
    putchar('N');
    state = stm;
  }
  else if (c == 212 || c == 244) {  /* Seen t or T so we have to output D and go to state sANY */
    putchar('D');
    state = stANY;
  }
  else {
    putchar('N');                /*Opoiosdhpote allos xarakthras*/
    printf("%c%c%c",cmap[c][0], cmap[c][1], cmap[c][2]);
    state = stANY;
  }
  return state;
}/* END sN */

int sM(int c,int cmap[][3]) /*seen M and we implement different states depending on what char seen so we can decide what to output */
{
  int state;  
  if (c == 204) {           /*Seen again M*/   
    putchar('M');            
    state = stM;
  }
  else if (c == 234) {   
    putchar('M');
    state = stm;
  }
  else if (c == 205) {
    putchar('M');
    state = stN;
  }
  else if (c == 237) {
    putchar('M');
    state = stn;
  }
  else if (c == 208 || c == 240) {   /*have seen p or P so we have to output B and go to state sANY*/
    putchar('B');
    state = stANY;
  }
  else {
    putchar('M');          /*Seen any c so we have to output Mc and to state sANY */
    printf("%c%c%c",cmap[c][0], cmap[c][1], cmap[c][2]);
    state = stANY;
  }
  return state;
}/* END sM */

int sm(int c,int cmap[][3]) /*seen n and we implement different states depending on what char seen so we can decide what to output */
{
  int state;
  if (c == 236) {           /*Seen again M*/         
    putchar('m');  
    state = stm;
  }
  else if (c == 204) {
    putchar('m');
    state = stM;
  }
  else if (c == 237) {
    putchar('m');
    state = stn;
  }
  else if (c == 205) {
    putchar('m');
    state = stN;
  }
  else if (c == 208 || c == 240) {  /*Seen p or P so we have to output b and go to state sANY*/
    putchar('b');
    state = stANY;
  }
  else {
    putchar('m');                 /*Seen any c so we have to output mc and go to state sANY */
    printf("%c%c%c",cmap[c][0], cmap[c][1], cmap[c][2]);
    state = stANY;
  }
  return state;



}/* END sm */


int sn(int c,int cmap[][3]) /*seen n and we implement different states depending on what char seen so we can decide what to output */
{
  int state;  
  if (c == 237) {          /*seen again n*/
    putchar('n');
    state = stn;
  }
  else if (c ==205) {
    putchar('n');
    state = stN;
  }
  else if (c == 236) {
    putchar('n');
    state = stm;
  }
  else if (c == 204) {
    putchar('n');
    state = stM;
  }
  else if (c == 244 || c == 212) {  /*Seen t or T so we have to output d and to go state sANY */
    putchar('d');
    state = stANY;
  }
  else {
    putchar('n');            /*Seen any c so we have to output Nc and then go to state sANY */
    printf("%c%c%c",cmap[c][0], cmap[c][1], cmap[c][2]);
    state = stANY;
  }
  return state;
}/* END sn */
