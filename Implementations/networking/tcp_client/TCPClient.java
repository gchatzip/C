/*
 * 	TCP Client
 */
import java.io.*; 
import java.net.*; 

public class TCPClient {
	 public static void main(String argv[]) throws Exception 
	 { 
		  String sentence; 
		  String modifiedSentence; 
		  String rundemo;
		  
		  System.out.print("Do you want to run the demo?(press y for yes):");
		  BufferedReader inFromUserd = 
				 new BufferedReader(new InputStreamReader(System.in)); 
		  	rundemo=inFromUserd.readLine();
		  if(rundemo.equals("y")){
		  System.out.print("CLIENT:");
		 
		   Socket clientSocket = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer = 
			 new DataOutputStream(clientSocket.getOutputStream()); 
        
		  BufferedReader inFromServer = /
			 new BufferedReader(new
			 InputStreamReader(clientSocket.getInputStream())); 

		  sentence ="2421 00012 1"; 
		  System.out.println(sentence);
		  outToServer.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  
		  
		  
		  
		  
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket17 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer17= 
			 new DataOutputStream(clientSocket17.getOutputStream()); 

		  BufferedReader inFromServer17 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket17.getInputStream())); 

		  sentence ="2421 00012 007011 3"; 
		  System.out.println(sentence);
		  outToServer17.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer17.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
	
		  
		  
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket1 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer1 = 
			 new DataOutputStream(clientSocket1.getOutputStream()); 
       
		  BufferedReader inFromServer1 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket1.getInputStream())); 

		  sentence ="2421 00013 1"; 
		  System.out.println(sentence);
		  outToServer1.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer1.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  
		  
		  
		 /* ---------------------------------------------------------------*/ 
		  
		  
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket2 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer2 = 
			 new DataOutputStream(clientSocket2.getOutputStream()); 
      
		  BufferedReader inFromServer2 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket2.getInputStream())); 

		  sentence ="2411 00013 1"; 
		  System.out.println(sentence);
		  outToServer2.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer2.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  
		  /* ---------------------------------------------------------------*/ 
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket3 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer3 = 
			 new DataOutputStream(clientSocket3.getOutputStream()); 
     
		  BufferedReader inFromServer3 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket3.getInputStream())); 

		  sentence ="2421 00014 1"; 
		  System.out.println(sentence);
		  outToServer3.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer3.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  /* ---------------------------------------------------------------*/ 
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket4 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer4 = 
			 new DataOutputStream(clientSocket4.getOutputStream()); 
    
		  BufferedReader inFromServer4 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket4.getInputStream())); 

		  sentence ="2421 00014 7"; 
		  System.out.println(sentence);
		  outToServer4.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer4.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  
		  /* ---------------------------------------------------------------*/ 
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket5 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer5 = 
			 new DataOutputStream(clientSocket5.getOutputStream()); 
   
		  BufferedReader inFromServer5 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket5.getInputStream())); 

		  sentence ="2421 00000914 12"; 
		  System.out.println(sentence);
		  outToServer5.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer5.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  /*--------------------------------------------------------------- TELOS PRWTHS DEMO PRWTHS LEITOURGIAS*/
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket6 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer6 = 
			 new DataOutputStream(clientSocket6.getOutputStream()); 
  
		  BufferedReader inFromServer6 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket6.getInputStream())); 

		  sentence ="2421 00013 00012 2"; 
		  System.out.println(sentence);
		  outToServer6.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer6.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  
		  
		  /* ---------------------------------------------------------------*/ 
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket7 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer7 = 
			 new DataOutputStream(clientSocket7.getOutputStream()); 
 
		  BufferedReader inFromServer7 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket7.getInputStream())); 

		  sentence ="2421 00012 00013 2"; 
		  System.out.println(sentence);
		  outToServer7.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer7.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  /* ---------------------------------------------------------------*/ 
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket8 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer8 = 
			 new DataOutputStream(clientSocket8.getOutputStream()); 
 
		  BufferedReader inFromServer8 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket8.getInputStream())); 

		  sentence ="2421 00012 00013 2"; 
		  System.out.println(sentence);
		  outToServer8.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer8.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  /* ---------------------------------------------------------------*/ 
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket9 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer9 = 
			 new DataOutputStream(clientSocket9.getOutputStream()); 
 
		  BufferedReader inFromServer9 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket9.getInputStream())); 

		  sentence ="2421 000122 1"; 
		  System.out.println(sentence);
		  outToServer9.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer9.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  /* ---------------------------------------------------------------*/ 
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket10 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer10 = 
			 new DataOutputStream(clientSocket10.getOutputStream()); 
 
		  BufferedReader inFromServer10 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket10.getInputStream())); 

		  sentence ="2421 00012 00013 2"; 
		  System.out.println(sentence);
		  outToServer10.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer10.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  /* ---------------------------------------------------------------*/ 
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket11 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer11 = 
			 new DataOutputStream(clientSocket11.getOutputStream()); 
 
		  BufferedReader inFromServer11 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket11.getInputStream())); 

		  sentence ="2421 00012 1"; 
		  System.out.println(sentence);
		  outToServer11.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer11.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  
		  /* ---------------------------------------------------------------*/ 
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket12 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer12 = 
			 new DataOutputStream(clientSocket12.getOutputStream()); 
 
		  BufferedReader inFromServer12 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket12.getInputStream())); 

		  sentence ="2421 00012 00013 2"; 
		  System.out.println(sentence);
		  outToServer12.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer12.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  /* ---------------------------------------------------------------*/ 
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket13 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer13 = 
			 new DataOutputStream(clientSocket13.getOutputStream()); 
 
		  BufferedReader inFromServer13 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket13.getInputStream())); 

		  sentence ="2421 00011 00013 2"; 
		  System.out.println(sentence);
		  outToServer13.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer13.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  
		  /* ---------------------------------------------------------------*/ 
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket14 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer14 = 
			 new DataOutputStream(clientSocket14.getOutputStream()); 
 
		  BufferedReader inFromServer14 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket14.getInputStream())); 

		  sentence ="2421 00012 00011 2"; 
		  System.out.println(sentence);
		  outToServer14.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer14.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  
		  /*------------------------------------------------------------------TELOS DEMO 2HS LEITOURGIAS-----*/
		  
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket15 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer15= 
			 new DataOutputStream(clientSocket15.getOutputStream()); 

		  BufferedReader inFromServer15 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket15.getInputStream())); 

		  sentence ="2421 00012 004011 3"; 
		  System.out.println(sentence);
		  outToServer15.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer15.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  
		  /*-------------------------------------------------------------------------------------------*/
		  
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket16 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer16= 
			 new DataOutputStream(clientSocket16.getOutputStream()); 

		  BufferedReader inFromServer16 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket16.getInputStream())); 

		  sentence ="2421 00012 007011 3"; 
		  System.out.println(sentence);
		  outToServer16.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer16.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
 /*-------------------------------------------------------------------------------------------*/
		  
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket18 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer18= 
			 new DataOutputStream(clientSocket18.getOutputStream()); 

		  BufferedReader inFromServer18 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket18.getInputStream())); 

		  sentence ="2421 00013 007011 3"; 
		  System.out.println(sentence);
		  outToServer18.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer18.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  
/*-------------------------------------------------------------------------------------------*/
		  
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket19 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer19= 
			 new DataOutputStream(clientSocket19.getOutputStream()); 

		  BufferedReader inFromServer19 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket19.getInputStream())); 

		  sentence ="2421 00018 007211 3"; 
		  System.out.println(sentence);
		  outToServer19.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer19.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  	  
		  
		/*-------------------------------------------------------------------------------------------*/
		  
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket20 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer20= 
			 new DataOutputStream(clientSocket20.getOutputStream()); 

		  BufferedReader inFromServer20 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket20.getInputStream())); 

		  sentence ="2421 00012 1"; 
		  System.out.println(sentence);
		  outToServer20.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer20.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);

		/*-------------------------------------------------------------------------------------------*/
		  
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket21 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer21= 
			 new DataOutputStream(clientSocket21.getOutputStream()); 

		  BufferedReader inFromServer21 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket21.getInputStream())); 

		  sentence ="2421 00013 1"; 
		  System.out.println(sentence);
		  outToServer21.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer21.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);



		/*-------------------------------------------------------------------------------------------*/
		  
		  System.out.print("CLIENT:");
			 
		   Socket clientSocket22 = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServer22= 
			 new DataOutputStream(clientSocket22.getOutputStream()); 

		  BufferedReader inFromServer22 = 
			 new BufferedReader(new
			 InputStreamReader(clientSocket22.getInputStream())); 

		  sentence ="24 000132 asdsd"; 
		  System.out.println(sentence);
		  outToServer22.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServer22.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);

		

		  System.out.print("CLIENT:");
		 
		   Socket clientSocketE = new Socket("fe80::211:9ff:fe8a:321a", 1281);

		  DataOutputStream outToServerE = 
			 new DataOutputStream(clientSocketE.getOutputStream()); 
        
		  BufferedReader inFromServerE = 
			 new BufferedReader(new
			 InputStreamReader(clientSocketE.getInputStream())); 

		  sentence ="2421 EXIT"; 
		  System.out.println(sentence);
		  outToServerE.writeBytes(sentence + '\n'); 

		  modifiedSentence = inFromServerE.readLine(); 
		  System.out.println("SERVER: " + modifiedSentence);
		  
		  if(modifiedSentence.length()==18){
			  
			//  System.out.println("SERVER:"+modifiedSentence);
			  clientSocket.close();
			  return;}
		  
		 
		//  clientSocket.close(); 
		  }
		  else
		  {
			  String sentencelo; 
			  String modifiedSentencelo; 
			  
			  while(true){
				  System.out.print("CLIENT:");
			  BufferedReader inFromUser = 
				 new BufferedReader(new InputStreamReader(System.in)); 

			   Socket clientSocket = new Socket("fe80::211:9ff:fe8a:321a", 1281);

			  DataOutputStream outToServer = 
				 new DataOutputStream(clientSocket.getOutputStream()); 
	        
			  BufferedReader inFromServer = 
				 new BufferedReader(new
				 InputStreamReader(clientSocket.getInputStream())); 

			  sentencelo = inFromUser.readLine(); 

			  outToServer.writeBytes(sentencelo + '\n'); 

			  modifiedSentencelo = inFromServer.readLine(); 

			  if(modifiedSentencelo.length()==18){
				  
				  System.out.println("SERVER:"+modifiedSentencelo);
				  clientSocket.close();
				  return;}
			  
			  System.out.println("SERVER: " + modifiedSentencelo); 
			//  clientSocket.close(); 
			  }
			  
		  }
		  
	 }       
	 

}

