/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define port_number 2222

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void readBuffer(int newsockfd)
{
    int n;
    // ------> THIS STRING IS WHERE THE BUFFER WILL STORE
    char buffer[256];
    char exit[] = "exit";

    while (1)
    {
        /**
         * 
         *  ------> LOOP FROM PREVIOUS PROGRAM THAT READ THE MESSAGE
         * 
         * */
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);
        if (n < 0)
            error("Error reading from socket");

        n = strcmp(buffer, exit);
        if (n == 0)
            break;

        printf("Here is the message: %s\n", buffer);

        n = write(newsockfd, "I got your message\n", 18);
        if (n < 0)
            error("Error writing to socket");
    }
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    // 1./ ADDED NEW PId and OPTVAL FOR SOCKET SETTING.
    int n, pid, optval;

    if (argc < 2)
    {
        fprintf(stderr, "Error, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    optval = 1;
    /**
     *  2./ CALL FUNCTION TO SET THE SOCKET.
     * */
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
    if (sockfd < 0)
        error("ERROR opening socket");
    bzero((char *)&serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *)&serv_addr,
             sizeof(serv_addr)) < 0)
        error("ERROR on binding");
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    /**
     *  3./ START LOOP WHILE(1)
     * 
     *  THIS MEANS THAT WHILE IT RECEIVES A RESPONSE THE CONNECTION WILL KEEP OPEN
     *  THUS READING THE BUFFER.
     * */
    while (1)
    {
        newsockfd = accept(sockfd,
                           (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0)
            error("Error on accept");
        /**
        *  4./ FORK PID (ID OF THE SOCKET).
        * */
        pid = fork();
        if (pid < 0)
            error("Error on fork");

        if (pid == 0)
        {
            /**
            *  5./ BEGIN READING OPERATION.
            * */
            close(sockfd);
            // ----> READS THE CHARACTERS AND TRANSLATES THE BUFFER.
            readBuffer(newsockfd);
            exit(0);
        }
        else
            // CLOSES THE SOCKET IF THE CONNECTION IS CLOSED SO IT WONT CYCLE.
            close(newsockfd);
    }
    return 0;
}
