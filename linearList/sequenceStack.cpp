#include <iostream>
#include "..\define.h"

// 顺序栈的存储结构
#define MAXSIZE 100
typedef int SElemType;
typedef struct __SqStack {
    SElemType *base, *top;
    int stackSize;
} Sqstack;

// 顺序栈的初始化
Status InitStack(Sqstack& S) {
    S.base = new SElemType[MAXSIZE];
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stackSize = MAXSIZE;
    return OK;
}

// 判断顺序栈是否为空
bool IsEmpty(Sqstack S) {
    return S.top == S.base;
}

// 求顺序栈的长度
int GetLength(Sqstack S) {
    return S.top - S.base;
}

// 顺序栈的清空
Status ClearStack(Sqstack S) {
    if (S.base)
        S.top = S.base;
    return OK;
}

// 顺序栈的销毁
Status DestroyStack(Sqstack& S) {
    if (S.base) {
        delete S.base;
        S.stackSize = 0;
        S.base = S.top = nullptr;
    }
    return OK;
}

// 顺序栈的入栈
Status Push(Sqstack& S, SElemType e) {
    if (S.top - S.base == S.stackSize)
        return ERROR;
    *S.top++ = e;
    return OK;
}

// 顺序栈的出栈
Status Pop(Sqstack& S, SElemType& e) {
    // 或：if (IsEmpty(S))
    if (S.top == S.base)
        return ERROR;
    e = --*S.top;
    return OK;
}

// 取栈顶元素
Status GetTop(Sqstack S, SElemType& e) {
    // 或：if (!IsEmpty(S))
    if (S.top == S.base)
        return ERROR;
    e = *(S.top - 1);
    return OK;
}