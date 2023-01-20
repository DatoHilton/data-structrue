#include <iostream>
#include "define.h"

// 顺序表的存储结构
#define MAXIZE 100
typedef int ElemType;
typedef struct __SqList {
    ElemType* elem;
    int length;
} SqList;

// 顺序表的初始化
Status InitList(SqList& L) {
    L.elem = new ElemType[MAXIZE];
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    return OK;
}

// 顺序表的销毁
void DestroyList(SqList& L) {
    if (L.elem)
        delete L.elem;
}

// 顺序表的清空
void ClearList(SqList& L) {
    L.length = 0;
}

// 求顺序表的长度
int GetLength(SqList L) {
    return L.length;
}

// 判断顺序表L是否为空
bool IsEmpty(SqList L) {
    if (L.length == 0)
        return true;
    else
        return false;
}

// 顺序表的取值
Status GetElem(SqList L, int i, ElemType& e) {
    if (i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];
    return OK;
}