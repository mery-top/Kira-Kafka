#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include "../include/logger.h"

void append_message_to_log(Partition* p, char* message){
    char log_file[300], index_file[300], timeindex_file[300];
    snprintf(log_file, sizeof(log_file), "%s/%020llu.log", "../temp/order1", p->log_offset);
    snprintf(index_file, sizeof(index_file), "%s/%020llu.log", "../temp/order1", p->log_offset);
    snprintf(timeindex_file, sizeof(timeindex_file), "%s/%020llu.log", "../temp/order1", p->log_offset);
    
    //Segment rotation
    if(p->log_offset % 2 == 0){
        snprintf(log_file, sizeof(log_file), "%s/%020llu.log", "../temp/order1", p->log_offset);
    }

    int log_fd = open(log_file, O_WRONLY | O_APPEND | O_CREAT, 0644);
    int idx_fd = open(index_file, O_WRONLY | O_APPEND | O_CREAT, 0644);
    int time_fd = open(timeindex_file, O_WRONLY | O_APPEND | O_CREAT, 0644);

    


}