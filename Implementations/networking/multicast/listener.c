/*
Implement a multicast client which broadcasts a particular message.
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define HELLO_PORT 14335
#define HELLO_GROUP "225.0.0.37"
#define MSGBUFSIZE 32

main(int argc, char *argv[])
{
     struct sockaddr_in addr;
     struct sockaddr_in ServAddr;     /* server address */
     int fd, nbytes,addrlen;
     struct ip_mreq mreq;
     char msgbuf[MSGBUFSIZE];
     char *destip;
     char *destport;
     char* message;
     int i,k=0;
     int sock;                        /* Socket descriptor */
     int lengthmes;

     u_int reuseaddr=1;
    destip=malloc(12*sizeof(char));
    destport=malloc(4*sizeof(char));
    message=strdup("2421  ");
    message[5]=*(argv[1]);
 

     /* create what looks like an ordinary UDP socket,it is need for multicast */
     if ((fd=socket(AF_INET,SOCK_DGRAM,0)) < 0) {
	  perror("socket");
	  exit(1);
     }

     /* allow multiple sockets to use the same PORT number,so we can run and another process like B or C */
     if (setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&reuseaddr,sizeof(reuseaddr)) < 0) {
          perror("Reusing ADDR failed");
          exit(1);
     }

     /* set up destination address so to listen to multicast message*/
     memset(&addr,0,sizeof(addr));
     addr.sin_family=AF_INET;
     addr.sin_addr.s_addr=htonl(INADDR_ANY); /* N.B.: differs from sender ????????????????*/
     addr.sin_port=htons(HELLO_PORT);
     
     /* bind to receive address */
     if (bind(fd,(struct sockaddr *) &addr,sizeof(addr)) < 0) {
	  perror("bind");
	  exit(1);
     }
     
     /* use setsockopt() to request that the kernel join a multicast group */
     mreq.imr_multiaddr.s_addr=inet_addr(HELLO_GROUP); /* IP multicast address of group */
     mreq.imr_interface.s_addr=htonl(INADDR_ANY); /* local IP address of interface */
     if (setsockopt(fd,IPPROTO_IP,IP_ADD_MEMBERSHIP,&mreq,sizeof(mreq)) < 0) {
	  perror("setsockopt");
	  exit(1);
     }



    
     	  addrlen=sizeof(addr);
	  if ((nbytes=recvfrom(fd,msgbuf,MSGBUFSIZE,0,
			       (struct sockaddr *) &addr,&addrlen)) < 0) {
	       perror("recvfrom");
	  }    // exit(1);
	
	  puts(msgbuf);


     	strncpy(destip,msgbuf,12);//get IP of mutlicast message
	destip[12]='\0';
	printf("to ip einai %s \n",destip);
	for(i=13;i<17;i++)
	{
	destport[k]=msgbuf[i];//get port of mutlicast message
	k++;
	}
	destport[5]='\0';
	int portdest=atoi(destport);
	

	/*destip->string , portdest->int kai destport->string*/

	
	printf("%s kai ",destip);
	printf("%d kai ip strlen einai %d \n",portdest,strlen(destip));

/* Create a reliable, stream socket using TCP */
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        printf("socket() failed\n");
	exit(-1);
    }


    memset(&ServAddr, 0, sizeof(ServAddr));     /* Zero out structure */
    ServAddr.sin_family      = AF_INET;             /* Internet address family */
    ServAddr.sin_addr.s_addr = inet_addr(destip);   /* Server IP address */
    ServAddr.sin_port        = htons(portdest); /* Server port */


    /*Establish the connection to the server*/
  
   while(connect(sock,(struct sockaddr*)&ServAddr,sizeof(ServAddr))<0){
	//printf("connect() failed\n");
	//exit(-1);
	}
	lengthmes=strlen(message);
	printf("connection OK \n");

	  /* Send the string to the server */
    if (send(sock,message,lengthmes, 0) != lengthmes) {
        printf("send() sent a different number of bytes than expected");
    }

    close(sock);
    exit(0);


}
