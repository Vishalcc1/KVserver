#include "iostream"

struct conf{
    int port,cache_size,thread_pool;
    std::string cache_replacement;
};
struct conf print();
