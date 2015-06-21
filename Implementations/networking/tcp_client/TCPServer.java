/*
 * TCP Server
 */
import java.io.*;
import java.net.*;
import java.util.*;

public class TCPServer
{

   public static void main(String argv[]) throws Exception
   {
      String am = "2421";
      String logariasmos1= "00012";
      String logariasmos2= "00013";/
      float ypoloipo1= 5000;
      float ypoloipo2= 0;
      int c=0;
      
      String outgoingSentence;
      String clientSentence;
      
      int port = 1281;
      
      ServerSocket welcomeSocket = new ServerSocket(port);

      System.out.println("Server ready on "+port);
      System.out.println("The connection been done");

      while(true){
         
    	  Socket connectionSocket = welcomeSocket.accept();
         BufferedReader inFromClient = 
            new BufferedReader(
               new InputStreamReader(connectionSocket.getInputStream()));

         DataOutputStream outToClient = 
            new DataOutputStream(connectionSocket.getOutputStream());

         String amc="\0";				
         String logarc="\0";
         String energeia="\0";
         String logarc2="\0";
         clientSentence = inFromClient.readLine();
         int len= clientSentence.length();
         if(len==12){ 				
          amc = clientSentence.substring(0,4);
          logarc= clientSentence.substring(5,10);
          energeia = clientSentence.substring(11,12);}
         else if(len==18){ 			
        	 amc = clientSentence.substring(0,4);
             logarc= clientSentence.substring(5,10);
        	  logarc2= clientSentence.substring(11,16);
        	 energeia=clientSentence.substring(17,18);
         }
         else if(len==19){			
        	 amc = clientSentence.substring(0,4);
             logarc= clientSentence.substring(5,10);
        	  logarc2= clientSentence.substring(11,14);
        	 energeia=clientSentence.substring(18,19);
        	 
         }
         else if(len==9)		
         {					
        	 amc = clientSentence.substring(0,4);
        	 String ex= clientSentence.substring(5,9);
        	 if(!amc.equals(am) || !(ex.equals("EXIT")))// Error 404
             { 
        		 if(!ex.equals("EXIT")){
                	 outgoingSentence = "id->"+amc+" 407 Error Bad Request"+'\n';

                     outToClient.writeBytes( outgoingSentence);}
        		 if(!amc.equals(am)){// type 2 Error 
            	 outgoingSentence = "id->"+amc+" 404 Error Aplicant Not Found"+'\n';

                 outToClient.writeBytes( outgoingSentence);}
        		
             }
        	 else{// CASE THAT MESSAGE IS COPACETIC
        	 outgoingSentence = "GOODBAY am->"+amc+" !"+'\n';
        	 outToClient.writeBytes( outgoingSentence);
        	 connectionSocket.close();
        	 return;}}
         else//in any other case we output Error 407
         {
        	 outgoingSentence = " 407 Error Bad Request"+'\n';
        	 outToClient.writeBytes( outgoingSentence);
         }
       
         
         
      
         
         if(!amc.equals(am))
         {
        	 outgoingSentence = "id->"+amc+" 404 Error Aplicant Not Found"+'\n';

             outToClient.writeBytes( outgoingSentence);
         }
         
         if(energeia.equals("1") && len==12)
         {
        	
             if(!(logarc.equals(logariasmos1))&& !(logarc.equals(logariasmos2)))
             {
            	 outgoingSentence = "id->"+amc+" 408 Error Account Number Not Found"+'\n';
            	 outToClient.writeBytes( outgoingSentence);
             }
             
        	 if(logarc.equals(logariasmos1))
        	 {
        		 c=0;
        		 String remain= Float.toString(ypoloipo1);
        		 outgoingSentence = "id->2421 200 OK :Your remaing cash into the account is "+remain+'\n';
        		 outToClient.writeBytes( outgoingSentence);
        	 }
        	 if(logarc.equals(logariasmos2))
        	 {
        		 c=0;
        		 String remain= Float.toString(ypoloipo2);
        		 outgoingSentence = "id->2421 200 OK :Your remaing cash into the account is "+remain+'\n';
        		 outToClient.writeBytes( outgoingSentence);
        	 }
        	 
         }
         else if(energeia.equals("2")&&len==18)
         {
        	 
        	 
        	
        	 if(c>1)/
        	 {
        		
            	 outgoingSentence = "id->"+amc+" 411 Error Permision To Transfer Money Denied"+'\n';
            	 outToClient.writeBytes( outgoingSentence);
        		 
        	 }
        
        	 
             if((!(logarc.equals(logariasmos1))&& !(logarc.equals(logariasmos2)))||(!(logarc2.equals(logariasmos1))&& !(logarc2.equals(logariasmos2))))
             {
            	 outgoingSentence = "id->"+amc+" 408 Error Account Number Not Found"+'\n';
            	 outToClient.writeBytes( outgoingSentence);
             }
             
             
        	 float moneytran;
        	 if(logarc.equals(logariasmos1))
        	 {
        		 if(ypoloipo1==0)
        		 {
        			 outgoingSentence = "id->2421 400 Error Money Cannot Be Transfered"+'\n';
            		 outToClient.writeBytes( outgoingSentence); 
        		 }
        		 c++;
        		 moneytran = ypoloipo1/3;
        		 ypoloipo1=ypoloipo1-moneytran;
        		 ypoloipo2=ypoloipo2+moneytran;
        		 outgoingSentence = "id->2421 200 OK :Your money has been transfered"+'\n';
        		 outToClient.writeBytes( outgoingSentence);
        	 }
        	 
        	 if(logarc.equals(logariasmos2))
        	 {
        		 if(ypoloipo2==0)
        		 {
        			 outgoingSentence = "id->2421 400 Error Money Cannot Be Transfered"+'\n';
            		 outToClient.writeBytes( outgoingSentence); 
        		 }
        		 c++;
        		 moneytran = ypoloipo2/3;
        		 ypoloipo2=ypoloipo2-moneytran;
        		 ypoloipo1=ypoloipo1+moneytran;
        		 outgoingSentence = "id->2421 200 OK :Your money has been transfered"+'\n';
        		 outToClient.writeBytes( outgoingSentence);
        	 }
        	 
        	 
         }
         else if(energeia.equals("3")&&len==19)
         {
        
        	
             if(!((logarc.equals(logariasmos1))) && !((logarc.equals(logariasmos2))))
             {
            	 outgoingSentence = "id->"+amc+" 408 Error Account Number Not Found"+'\n';
            	 outToClient.writeBytes( outgoingSentence);
             }
             
            if(!(logarc2.equals("007")))
             {
            	 outgoingSentence = "id->"+amc+" 409 Error Electricity Account Number To Be Paid Not Found "+'\n';
            	 outToClient.writeBytes( outgoingSentence);
            	 
             }
             
             
        	 if(logarc.equals(logariasmos2)){
        	 Random generator = new Random();
        	 int posoplhrwm = generator.nextInt(7000);
        	 
        	 if(ypoloipo2>=0 && ypoloipo2>= posoplhrwm){
        		 c=0;
        	 ypoloipo2=ypoloipo2-posoplhrwm;
        	 outgoingSentence = "id->2421 200 OK : The Electricity Money Isuue Has Been Payed"+'\n';
    		 outToClient.writeBytes( outgoingSentence);}
        	 else{
        		 outgoingSentence = "id->2421 405 Error Account For Electricity Cannot Be Paid Due Money Issue"+'\n';
        		 outToClient.writeBytes( outgoingSentence);
        	 }
        	 
        	 }
        	 
        	 if(logarc.equals(logariasmos1)){
            	 Random generator = new Random();
            	 int posoplhrwm = generator.nextInt(7000);
            	 
            	
            	 if(ypoloipo1>=0 && ypoloipo1>= posoplhrwm){
            		 c=0;
            	 ypoloipo1=ypoloipo1-posoplhrwm;
            	 outgoingSentence = "id->2421 200 OK : The Electricity Money Isuue Has Been Payed"+'\n';
        		 outToClient.writeBytes( outgoingSentence);}
            	 else
            	 {
            		 outgoingSentence = "id->2421 405 Error Account For Electricity Cannot Be Paid Due Money Issue"+'\n';
            		 outToClient.writeBytes( outgoingSentence);
            		 
            	 }
            		 
            }
        	 
        	 
         }
         else
         {
        	 
            	 outgoingSentence = " 407 Error Bad Request"+'\n';
            	 outToClient.writeBytes( outgoingSentence);
             
         }
         
         String tring = "OK";
         outgoingSentence = tring + '\n';

         outToClient.writeBytes(outgoingSentence);
      
      }
      
   }
}


