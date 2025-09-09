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
    struct sockaddr_in servaddr, cliaddr; 
 


    //Creating the Socket and Specifying the Domain , Type of Protocol used, Protocol (0 by Default)
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    memset(&servaddr, 0, sizeof(servaddr)); // DEclares/Specify the Server Address and Client Address
    memset(&cliaddr, 0, sizeof(cliaddr)); 
 
    //Specifying the essential information of the Sockets such as Family, adsress
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); // Converts the port number into Network Byte order

    
    //Binds the socket address with the server 
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    socklen_t len;
    int n; 
    len = sizeof(cliaddr); 

    //Recieves the message FRom the Client
    n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &cliaddr, &len); 
    buffer[n] = '\0'; 
    cout<<"Client :"<<" "<<buffer<<endl;

    
    string userInput;
    cout << "Enter message to send to client: ";
    getline(cin, userInput);

    //Here we Send message Back to Client
    sendto(sockfd, userInput.c_str(), userInput.length(), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len); 
    cout << "Message sent to client." << endl;  

    return 0; 
}
