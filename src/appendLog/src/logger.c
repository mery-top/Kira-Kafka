#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <sys/stat.h>
#include "../include/logger.h"

void append_message_to_log(Partition* p, char* message){
    char log_file[300], index_file[300], timeindex_file[300];
    mkdir("temp", 0755);
    mkdir("temp/order1", 0755);

    //Segment Rotation
    uint64_t base_offset = (p->log_offset/2)*2;

    snprintf(log_file, sizeof(log_file), "%s/%020llu.log", "temp/order1", base_offset);
    snprintf(index_file, sizeof(index_file), "%s/%020llu.index", "temp/order1", base_offset);
    snprintf(timeindex_file, sizeof(timeindex_file), "%s/%020llu.timeindex", "temp/order1", base_offset);

    int log_fd = open(log_file, O_WRONLY | O_APPEND | O_CREAT, 0644);
    int idx_fd = open(index_file, O_WRONLY | O_APPEND | O_CREAT, 0644);
    int time_fd = open(timeindex_file, O_WRONLY | O_APPEND | O_CREAT, 0644);

    if(log_fd < 0){
        perror("open error");
        return;
    }

    off_t offset = lseek(log_fd, 0 , SEEK_END);
    size_t len = strlen(message);

    write(log_fd, message, len);
    write(log_fd, "\n", 1);

    dprintf(idx_fd, "%llu,%lld\n", p->log_offset, (long long)offset);

    time_t now = time(NULL);
    dprintf(time_fd, "%ld,%lld\n", now, (long long)offset);

    fsync(log_fd);
    fsync(idx_fd);
    fsync(time_fd);

    close(log_fd);
    close(idx_fd);
    close(time_fd);

    p->log_offset++;

}