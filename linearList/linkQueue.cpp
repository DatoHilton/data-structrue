#include <iostream>
#include "..\define.h"

// 队列的链式存储结构
typedef int QElemType;
typedef struct __QNode {
    QElemType data;
    struct __QNode* next;
} QNode, *QueuePtr;
typedef struct __LinkQueue {
    QueuePtr front, rear;
} LinkQueue;

// 链队的初始化
Status InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = new QNode;
    if (!Q.front)
        exit(OVERFLOW);
    Q.front->next = NULL;
    return OK;
}

// 链队的销毁
Status DestroyQueue(LinkQueue& Q) {
    while (Q.front) {
        QNode* p = Q.front->next;
        delete Q.front;
        Q.front = p;
        // 或：用尾指针代替p可节省一个变量
        // Q.rear = Q.front->next;
        // delete Q.front;
        // Q.front = Q.rear;
    }
    return OK;
}

// 链队的入队
Status EnQueue(LinkQueue& Q, QElemType e) {
    QNode* p = new QNode;
    if (!p)
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

// 链队的出队
Status DeQueue(LinkQueue& Q, QElemType& e) {
    if (Q.front == Q.rear)  // 队空
        return ERROR;
    QNode* p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)  // 如果最后一个元素出队
        Q.rear = Q.front;
    delete p;
    return OK;
}

// 取队头元素
QElemType GetHead(LinkQueue Q) {
    if (Q.front != Q.rear)  // 队非空
        return Q.front->next->data;
}