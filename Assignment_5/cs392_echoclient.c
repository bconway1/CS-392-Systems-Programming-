//“I pledge my honor that I have abided by the Stevens Honor System.” -Brereton Conway

// Created by bconway on 5/5/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


#define BUFFER_SIZE 256

int main(int argc, char* argv[]){
  //check argv
    if(argc != 3){
        printf("please specify ONE ip address and ONE port number");
        exit(0);
    }
    //variables
    int client_socket;
    struct sockaddr_in echo_server_in;
    memset(&echo_server_in, '\0', sizeof(echo_server_in));
    char message[BUFFER_SIZE];
    char echo[BUFFER_SIZE];
    size_t message_len;
    ssize_t echo_len, bytes_sent;

    //create socket and checking and fill in info
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket == -1){
        perror("could not create socket");
        exit(1);
    }
    echo_server_in.sin_family = AF_INET;
    echo_server_in.sin_addr.s_addr = inet_addr(argv[1]);
    echo_server_in.sin_port = htons(atoi(argv[2]));
    //connect to address specified in argv's
    if(connect(client_socket, (struct sockaddr*) &echo_server_in, sizeof(echo_server_in)) == -1){
        perror("error with connecting the client");
        exit(0);

    }
    //sends a msg to server
    printf("Please type a message to be echoed by the server\n");
    fgets(message, BUFFER_SIZE, stdin);
    message_len = strlen(message);
    bytes_sent = send(client_socket, message, message_len, 0);
    if(bytes_sent == -1){
        perror("error sending msg from client");
        exit(0);
    }
    //the server send back the same message
    echo_len = recv(client_socket, echo, BUFFER_SIZE - 1, 0);
    if(echo_len == -1){
        perror("error receiving msg from client");
        exit(0);
    }
    echo[echo_len + 1] = '\0';
    printf("%s", echo);
    //close socket
    close(client_socket);

}
