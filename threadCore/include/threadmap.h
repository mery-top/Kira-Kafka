#pragma once

void* network_io_thread(void *args);
void* log_flush_thread(void *args);
void* consumer_thread(void *args);
void bind_thread_to_core(int core_id);
