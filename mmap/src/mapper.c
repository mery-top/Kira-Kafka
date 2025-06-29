#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "../include/mapper.h"

void read_log_with_mmap(char* filepath){
    int fd = open(filepath, O_RDONLY);
    if(fd <0){
        perror("open error");
        return;
    }

    struct stat st;
    fstat(fd, &st);

    size_t length = st.st_size;
    char *mapped = mmap(NULL, length, PROT_READ, MAP_SHARED, fd, 0);
    if(mapped == MAP_FAILED){
        perror("map error");
        close(fd);
        return;
    }

    printf("Readfile using mmap: \n");

    fwrite(mapped, 1, length, stdout);
    munmap(mapped, length);
    close(fd);
}