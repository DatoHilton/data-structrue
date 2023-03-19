#include <iostream>
#include "..\define.h"

// 队列的顺序存储结构
#define MAXSIZE 100
typedef int QElemType;
typedef struct __SqQueue {
    QElemType* base;
    int front, rear;
} SqQueue;

// 循环队列的初始化
Status InitQueue(SqQueue& Q) {
    Q.base = new QElemType[MAXSIZE];
    if (!Q.base)
        exit(OVERFLOW);
    Q.front = Q.rear = 0;
    return OK;
}

// 求循环队列的长度
int GetLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

// 循环队列的入队
Status EnQueue(SqQueue& Q, QElemType e) {
    if ((Q.rear + 1) % MAXSIZE == Q.front)  // 队满
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return OK;
}

// 循环队列的出队
Status DeQueue(SqQueue& Q, QElemType& e) {
    if (Q.front == Q.rear)  // 队空
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return OK;
}

// 取循环队列的队头元素
Status GetHead(SqQueue Q, QElemType& e) {
    if (Q.front == Q.rear)  // 队空
        return ERROR;
    e = Q.base[Q.front];
    return OK;
}