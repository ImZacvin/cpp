#include <stdio.h>
#include <stdlib.h> 
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

int main() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("Error");
        exit(1);
    }

    int opt = 1;

    int setOption = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if(setOption == -1) {
        perror("Set socket option error");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    int result = bind(fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if(result == -1) {
        perror("Error bind address");
        exit(1);
    }

    int listenResult = listen(fd, 5);
    if(listenResult == -1) {
        perror("Listen Error");
        exit(1);
    }
    sleep(30);
}