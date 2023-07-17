#include <iostream>
#include "..\define.h"

// 串的链式存储结构
#define CHUNKSIZE 80
typedef struct __Chunk {
    char ch[CHUNKSIZE];
    struct __Chunk* next;
} Chunk;
typedef struct __LString {
    Chunk *head, *tail;
    int curlen;
} LString;
