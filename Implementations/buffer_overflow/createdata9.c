/* Giorgos Xatzipantelis
   AM:2489
   File:createdata6.c
   Assignment6      */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAYSIZE 50


int array[ARRAYSIZE]=
{
   'G','i','o','r','g','o','s',' ','X','.','\0',' ',' ', ' ',' ',' ',0xc6, 0x05,0x6c, 0x00,
0x0b,0x08, 0x39, 0xb8, 0xd6, 0x82, 0x04, 0x08, 0xff, 0xe0 ,0x1e, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0x28, 0xf9, 0xff, 0x6f, 0xe8, 0x1b, 0x0b, 0x08, 0xd8,
0x1b, 0x0b, 0x08
};
/*Ta 0xc6, 0x05 einai to opcode gia to moveb, meta ta 0x6c, 0x00, 0x0b, 0x08 einai
 * i dieuthinsh pou vrisketai to grade kai tha allaksw me thn timh 0x39 (ascii gia to 9)
 * meta to 0xb8 einai to opcode ths movl, akolouthei h dieuthinsh 0x080482d6
 * pou einai ekei pou thelw na epistrepsw pou apothikeuetai ston $eax, enw me ta 
 * bytes 0xff, 0xe0 ginetai jmp ekei pou deixnei o $eax. 
 * Meta apo auta ekana akrivws oti ekana kai sthn ask6 apla anti gia RA thn dieuthinsh
 * ths main, evala thn dieuthinsh tou Name+16 gia na arxhsei h ektelsh twn entolwn assembly.
 */
int main(void) {
        int cnt;
        FILE *fp;
        fp=fopen("data9","w");
        for(cnt=0; cnt<ARRAYSIZE; cnt++)
                fputc(array[cnt],fp);
        fclose(fp);
    return 0;
}
