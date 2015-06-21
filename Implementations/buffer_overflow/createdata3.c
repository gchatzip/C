#include <stdio.h>
/* Giorgos Xatzipantelis 
    AM:2489             
    File:createdata3.c    
    Assignment6            */
    
/* Programm crash occurs because we give an input that is 010101010101010101010101010101010101 and the buffer is being overruned with the result to have its return address being overwritten
after that the programm attempts to return where it should but since the return address is lost the core dump error occurs..*/

int main(void)
{
FILE *fp;

fp = fopen("data3","w"); /* creates the desired data3 file */
fprintf(fp,"010101010101010101010101010101010101");

fclose(fp);

return 0;

}/*End of main */