

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>

void wakeup(int);  /* forward declaration */
int count = 0;     /* global counter */
int rings = 1; 	   /* number of signals received */
int done  = 0;	   /* are we done? */

void alarm_microsec(long int);



#define HELLO_PORT 14335/*arithmos portas multicasting group*/
#define HELLO_GROUP "225.0.0.37"
#define MAXPENDING 5    /* Maximum outstanding connection requests */
#define RCVBUFSIZE 6   /* Size of receive buffer */

main(int argc, char *argv[])
{
     struct sockaddr_in addr;/*For IPv4 addressing*/
     struct sockaddr_in ServAddr;     /* Local address */
     struct sockaddr_in ClntAddr;     /* Client address */
     int servSock;           /* Socket descriptor for TCP server */
     int clntSock;                    /* Socket descriptor for client */
     unsigned int clntLen;            /* Length of client address data structure */
     int fd, cnt, nbytes;
     struct ip_mreq mreq;
     char*  message;
	char sendm[17];
     char* messageport;//to miso message pou tha fygei
     FILE *fp;//o pointer ston file
     char namepc[12];//to name tou pc pou borei na einai 12 by default
     char *hostname;//to onoma tou ekastote host
     char *ipserv;//to ip tou ekastote server
     struct hostent *he;//domes pou voithane sto na vroume to ip by hostname
     struct in_addr **addr_list;//an exei parapanw apo ena ip
     char* incom;
     int recvMsgSize=0;                 /* Size of received message */
     int p2=2421;/*porta TCP socket sto opoio tha akouei h diergasia*/
     int N=0,i;
     struct sigaction sigact;
     sigset_t  sigset;
	incom=malloc(RCVBUFSIZE*sizeof(char));
	
	/* set up handler for the timer alarm */

        sigemptyset(&sigset); /* create an empty signal mask set.
	The sigemptyset() function initialises the signal set pointed to by set, 
	such that all signals defined in this document are excluded.*/

        sigact.sa_handler = wakeup; /* use the wakeup() handler.It is pointer to a signal handling function.*/

        sigact.sa_mask    = sigset; /* use the empty sigset */

        sigact.sa_flags   = SA_RESTART; 
	/* restart interrupted system calls.sa_flags specifies a set of flags which modify 
	the behaviour of the signal handling process.*/

        sigaction(SIGALRM, &sigact, NULL);/*The sigaction system call is used to change 
	the action taken by a process on receipt of a specific signal.*/





	if((fp=fopen("/proc/self/root/etc/hostname","r"))==NULL){
	printf("File could not be opended,need to be given by hand the IP");
	return 0;
	}
	fscanf(fp,"%s",namepc);
	int k=strlen(namepc);
	hostname=malloc((k+11)*sizeof(char));
	strncpy(hostname,namepc,strlen(namepc));
	strcat(hostname,".csd.uoc.gr");
	printf("to hostname einai %s kai strlen einai %d\n",hostname,strlen(hostname));
	he=gethostbyname(hostname);
//	addr_list = (struct in_addr **)he->h_addr_list;
	ipserv=strdup(inet_ntoa(*((struct in_addr *)he->h_addr)));
	printf("%s me strlen %d\n",ipserv,strlen(ipserv));
	message=calloc((strlen(ipserv)+5),sizeof(char));
        strncpy(message,ipserv,12);
	strcat(message," 2421");

//	sendm=calloc(strlen(message),sizeof(char));
	strcpy(sendm,message);
	printf("to teliko message einai %s me strlen %d\n",message,strlen(message));
	fclose(fp);
//	return 0;
     /* create what looks like an ordinary UDP socket.If successful, 
	socket() returns a valid socket descriptor; 
	otherwise it returns -1 and sets errno to indicate the error. */
     if ((fd=socket(AF_INET,SOCK_DGRAM,0)) < 0) {/*AF_INET address family socket is connectionless (type SOCK_DGRAM).*/
	  perror("socket");
	  exit(1);
     }

     /* set up destination address */
     memset(&addr,0,sizeof(addr));
     addr.sin_family=AF_INET;
     addr.sin_addr.s_addr=inet_addr(HELLO_GROUP);
	/*The inet_addr() function shall convert the string , in the standard
 	IPv4 dotted decimal notation, to an integer value suitable for use as an Internet address.*/

     addr.sin_port=htons(HELLO_PORT);
	/*The htons() function converts the unsigned short integer 
	hostshort from host byte order to network byte order. */
     
	 /* Create TCP socket for incoming connections */
    	if ((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        printf("socket() failed\n");
	exit(-1);
    	}


	
	/* Construct local address structure */
    	memset(&ServAddr, 0, sizeof(ServAddr));   /* Zero out structure */
    	ServAddr.sin_family = AF_INET;                /* Internet address family */
    	ServAddr.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
    	ServAddr.sin_port = htons(p2);      		/* Local port */

	

   /* Bind to the local address */
    if (bind(servSock, (struct sockaddr *) &ServAddr, sizeof(ServAddr)) < 0) {
        printf("bind() failed");
	exit(-1);
    }

    /* Mark the socket so it will listen for incoming connections */
    if (listen(servSock, MAXPENDING) < 0) {
        printf("listen() failed");
	exit(-1);
    }
	int x;
	x=fcntl(servSock,F_GETFL,0);
	fcntl(servSock,F_SETFL,x | O_NONBLOCK);
     /* now just sendto() our destination!,edw tha stelnei to multicast message kai tha exoume k tn tcp connection?? */
     nbytes=0;
     while (1) {
//	printf("ela re psile\n");     
	
	 alarm_microsec(2000000);
	  if (nbytes=sendto(fd,sendm,sizeof(sendm),0,(struct sockaddr *)&addr,sizeof(addr)) < 0) {
	       perror("sendto");
	       exit(1);
	  }
	
	  printf("%d\n", nbytes);

	  /* Set the size of the in-out parameter */
        clntLen = sizeof(ClntAddr);

	while(!done)
	count++;
	rings=1;
	done=0;
  	
        /* Wait for a client to connect*/ 
       clntSock = accept(servSock, (struct sockaddr *) &ClntAddr,&clntLen);

	recvMsgSize=recv(clntSock,incom,RCVBUFSIZE,0);

	
	if(recvMsgSize>0)
	{
		N++;
		printf("%s N=%d\n",incom,N);
		recvMsgSize=0;
	}

     }
}


/*
 * Alarm handler
 *
 */
void wakeup(int s)
{
	printf("woke up\n");

	if (++rings<=1) 
		alarm_microsec(2000000);
	else
		done = 1;
}

/*
 * 1 millisec = 1000 microsec
 * 1 sec = 1000 millisec
 */
void alarm_microsec(long int micro_sec)
{
	int ret_val;
	struct itimerval old, new;

        long int sec = (micro_sec) / 1000000;

	new.it_interval.tv_usec = 0;
	new.it_interval.tv_sec = 0;
	new.it_value.tv_usec = (micro_sec) - sec*1000000;
	new.it_value.tv_sec = sec;

	ret_val = setitimer (ITIMER_REAL, &new, &old);
	if( ret_val < 0 ) {
		fprintf(stdout, "ERROR: alarm_microsec:setitimer\n");
		exit(-1);
	}
}


