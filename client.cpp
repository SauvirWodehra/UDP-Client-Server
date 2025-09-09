#include <bits/stdc++.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT     8080 
#define MAXLINE  1024 

using namespace std;

int main() { 
    int sockfd; 
    char buffer[MAXLINE]; 
    struct sockaddr_in servaddr; 



     //Creating the Socket and Specifying the Domain , Type of Protocol used, Protocol (0 by Default)
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    memset(&servaddr, 0, sizeof(servaddr)); 

    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 


    string userInput;
    cout << "Enter message to send to server: ";
    getline(cin, userInput);

    sendto(sockfd, userInput.c_str(), userInput.length(), MSG_CONFIRM, 
           (const struct sockaddr *) &servaddr, sizeof(servaddr)); 
    cout << "Message sent to server." << endl; 


    socklen_t len = sizeof(servaddr); 
    int n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, 
                     (struct sockaddr *) &servaddr, &len); 
    buffer[n] = '\0'; 
    cout << "Server: " << buffer << endl; 

    close(sockfd); 
    return 0; 
}
