#pragma once
#define MAX_PARTITIONS 8
#define MAX_MESSAGES 100   

typedef struct{
    char* messages[MAX_MESSAGES];
    int count;
} Partition;

typedef struct{
    char name[64];
    Partition partitions[MAX_PARTITIONS];
    int partition_count;
    int rr_index;
} Topic;