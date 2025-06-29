#include <stdio.h>
#include "include/mapper.h"

int main(){
    char *logfile = "../appendLog/temp/order1/00000000000000000000.log";
    read_log_with_mmap(logfile);
    return 0;
}