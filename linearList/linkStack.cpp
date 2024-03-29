#include <iostream>
#include "..\define.h"

// 栈的链式存储结构
typedef int SElemType;
typedef struct __StackNode {
    SElemType data;
    struct __StackNode* next;
} StackNode, *LinkStack;

/* 注：
1.链表的头指针指向栈顶(a_n)
2.链栈不需要头结点
3.基本不存在栈满的情况
4.空栈相当于头指针指向空 */

// 链栈的初始化
Status InitStack(LinkStack& S) {
    S = nullptr;  // 空栈：头指针（栈顶指针）置空
    return OK;
}

// 判断链栈是否为空
Status IsEmpty(LinkStack S) {
    return S == nullptr;
}

// 链栈的入栈
Status Push(LinkStack& S, SElemType e) {
    StackNode* p = new StackNode;
    p->data = e;
    p->next = S;
    S = p;
    return OK;
}

// 链栈的出栈
Status Pop(LinkStack& S, SElemType& e) {
    if (S == nullptr)
        return ERROR;
    e = S->data;
    StackNode* p = S;
    S = S->next;
    delete p;
    return OK;
}

// 取链栈的栈顶元素
Status GetTop(LinkStack S, SElemType& e) {
    if (S == nullptr)
        return ERROR;
    e = S->data;
    return OK;
}