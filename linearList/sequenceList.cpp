#include <iostream>
#include "..\define.h"

// 顺序表的存储结构
#define MAXSIZE 100
typedef int ElemType;
typedef struct __SqList {
    ElemType* elem;
    int length;
} SqList;

// 顺序表的初始化
Status InitList(SqList& L) {
    L.elem = new ElemType[MAXSIZE];
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
    return L.length == 0;
}

// 顺序表的取值
Status GetElem(SqList L, int i, ElemType& e) {
    if (i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];
    return OK;
}

// 顺序表的查找
int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e)
            return i + 1;
    }
    return 0;
}

// 顺序表的插入
Status ListInsert(SqList& L, int i, ElemType e) {
    if ((i < 1) || (i > L.length + 1))
        return ERROR;
    if (L.length == MAXSIZE)
        return ERROR;
    for (int j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j];
    L.elem[i - 1] = e;
    L.length++;
    return OK;
}

// 顺序表的删除
Status ListDelete(SqList& L, int i) {
    if ((i < 1) || (i > L.length))
        return ERROR;
    for (int j = i; j <= L.length - 1; j++)
        L.elem[j - 1] = L.elem[j];
    L.length--;
    return OK;
}