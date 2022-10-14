#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "hacking.h"

#define PORT 6969

int main(void){
//host means server

	int host_file_desc, client_file_desc;  			//The file descriptors and the sockaddr_in structs are the
	struct sockaddr_in host_address, client_address;	//fundamental building blocks of the server
	socklen_t client_address_legnth;
	char buffer[1024];
	int receipt = 1;

	host_file_desc = socket(PF_INET, SOCK_STREAM, 0);	//define host file descriptor with output of socket function, which is an int
								//PF_INET and SOCK_STREAM together will give a TCP over IPv4, 0

	//before you can use any struct you must define the needed parts. host_address will be part of the bind function after typecasting
	//family, port, addr, and zero are the elements of struct sockaddr_in	
	host_address.sin_family = AF_INET;			//AF_INET for IPv4		
	host_address.sin_port = htons(PORT);			//Changes the port number from little endian to big endian to match TCP/IP
	host_address.sin_addr.s_addr = 0;				//Setting 0 will automatically fill with host IP address
	//host_address.sin_zero[8] = ??				//The book zeros this but doesn't say why. "zero if you want" says internet

	//host_file_desc is the first arguement - "bind host socket to the port!"
	//next two arguments are the address structure and its legnth
	//second argument needs to be typecast from sockaddr_in to sockaddr because bind() is looking for a generic socket struct, not IP specific
	bind(host_file_desc, (struct sockaddr*)&host_address, sizeof(struct sockaddr));

	listen(host_file_desc, 10); //who is listening and the size of the backlog cue

	//now we need to build an accept loop. while(1) will keep the program running until it is terminated
	while(1){
		client_address_legnth = sizeof(struct sockaddr_in);
		//first arguement is who is accepting, aka host. 
		//Second arguement is the typecasted client address struct. 
		//Third is legnth of the struct. The function writes the address into the struct.
		accept(host_file_desc, (struct sockaddr*)&client_address, &client_address_legnth);

		//You now have a functioning host socket! It will bind to a port, listen to a connection, and accept the connection!
		//Below we use the send and recieve functions to prove the connection
		printf("You are connectedto %s\n", inet_ntoa(client_address.sin_addr)); //convert client IP address from data to string
		//Who you are sending the data to, the data, the size of the data, and flags (we use 0)
		send(client_file_desc, "Hello friend\n", 13, 0);
		receipt = recv(client_file_desc, &buffer, 1024, 0);
		while(receipt > 0){
			printf("%d bytes sent\n", receipt);
			receipt = recv(client_file_desc, &buffer, 1024, 0);
			}
		close(client_file_desc);		
	}
		
	return 0;
	
}