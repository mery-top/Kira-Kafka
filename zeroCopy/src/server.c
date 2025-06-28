#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include "../include/server.h"

void start_server(char* filepath, int port){
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(port)
    };

    bind(server_fd, (struct socketaddr*)&addr, sizeof(addr));
    listen(server_fd, 1);

    printf("Server Listening at Port %d\n", port);

    
}