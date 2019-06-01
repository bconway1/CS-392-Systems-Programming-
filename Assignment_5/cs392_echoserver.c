//“I pledge my honor that I have abided by the Stevens Honor System.” -Brereton Conway

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "cs392_log.h"
#include <unistd.h>

#define MAX_PENDING_QUE 5
#define BUFFER_SIZE 256

int main(int argc, char* argv[]) {
  // check arguements
    if(argc != 2){
        printf("please specify ONE port number");
        exit(0);
    }
    if(atoi(argv[1]) > 65534){
        printf("port number too big");
        exit(0);
    }
    //our variables
    int port_number = atoi(argv[1]);
    struct sockaddr_in echo_server_in, echo_client_in;
    int echo_client_in_len = sizeof(echo_client_in);
    int server_socket, client_socket;
    char buffer[BUFFER_SIZE];
    char echo_response[BUFFER_SIZE];
    ssize_t message_len, bytes_sent;
    //create and check socket
    server_socket = socket(AF_INET,SOCK_STREAM, 0);

    if(server_socket == -1){
        perror("could not create socket");
        exit(1);
    }
    //set the sockaddr_in structs to null
    //we only have info for echo_server_in right now
    memset(&echo_client_in, '\0', sizeof(echo_client_in));
    memset(&echo_server_in, '\0', sizeof(echo_server_in));
    echo_server_in.sin_family = AF_INET;
    echo_server_in.sin_addr.s_addr = htonl(INADDR_ANY);
    echo_server_in.sin_port = htons((uint16_t)port_number);
    //bind and check
    if(bind(server_socket, (struct sockaddr*) &echo_server_in, sizeof(echo_server_in)) != 0){
        perror("error binding the socket");
        exit(0);
    }

    //listen with up to MAX_PENDING_QUE clients in que
    if(listen(server_socket, MAX_PENDING_QUE) != 0){
        perror("error listen for incoming connections");
        exit(0);
    }

    while(1) {
      // accept and check client
        client_socket = accept(server_socket, (struct sockaddr *) &echo_client_in, &echo_client_in_len);
        if (client_socket == -1) {
            perror("error with accepting client");
            exit(0);
        }
        //log ip and port addresses
        cs392_socket_log(echo_client_in.sin_addr, echo_client_in.sin_port);
        //recieve msg from client, checking the length for error
        message_len = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if(message_len == -1){
            perror("error receiving msg from client");
            exit(0);
        }
        //copy over the msg to echo, ensuring a null byte
        strncpy(echo_response, buffer, message_len);
        echo_response[message_len + 1] = '\n';
        //send and check
        bytes_sent = send(client_socket, echo_response, message_len + 1, 0);
        if(bytes_sent == -1){
            perror("error sending echo");
            exit(0);
        }
        //reset strings
        memset(buffer, '\0', sizeof(buffer));
        memset(echo_response, '\0', sizeof(echo_response));
        //close socket
        close(client_socket);


    }

}
