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

    while(1){
        int client_fd = accept(server_fd, NULL, NULL);
        printf("Client connected sending the file %s\n", filepath);

        int file_fd = open(filepath, O_RDONLY);
        if(file_fd<0){
            perror("open");
            close(client_fd);
            continue;
        }

        struct stat st;
        fstat(file_fd, &st);
        off_t offset = 0;

        sendfile(client_fd, file_fd, &offset, st.st_size);
        close(file_fd);
        close(client_fd);
        printf("Sent %ld bytes from %s using zero-copy", (long)st.st_size, filepath);
    }
}