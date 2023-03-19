#include <iostream>
#include "..\define.h"

// 单链表的存储结构
typedef int ElemType;
typedef struct __LNode {
    ElemType data;
    struct __LNode* next;
} LNode, *LinkList;

/* 注：
头指针一般定义为LinkList L
指向结点的指针一般定义为Lnode *p
几个重要操作：
p = L;  // p指向头结点
p = L->next;  // p指向首元结点
p = p->next;  // p指向下一结点 */

// 单链表的初始化
Status InitList(LinkList& L) {
    L = new LNode;
    L->next = nullptr;
    return OK;
}

// 判断单链表是否为空
bool IsEmpty(LinkList L) {
    if (L->next)
        return false;
    else
        return true;
}

// 单链表的销毁（不保留头指针和头结点）
Status DestroyList(LinkList& L) {
    LNode* p;
    while (L) {
        p = L;  // p指向头结点
        L = L->next;
        delete p;
    }
    return OK;
}

// 单链表的清空（保留头指针和头结点）
Status ClearList(LinkList& L) {
    LNode *p, *q;
    p = L->next;  // p指向首元结点
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }
    L->next = nullptr;  // 头结点指针域置空
    return OK;
}

// 求单链表的表长
int GetLength(LinkList L) {
    LNode* p = L->next;
    int length = 0;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

// 单链表的取值
Status GetElem(LinkList L, int i, ElemType& e) {
    LNode* p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    // 运行到这有三种情况：
    // 1. j==i：找到了
    // 2. p为空：没找到
    // 3. j<i：i太小了
    if (!p || j > i)
        return ERROR;
    e = p->data;
    return OK;
}

// 单链表的按值查找
LNode* LocateElem(LinkList L, ElemType e) {
    LNode* p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}

// 单链表的插入
Status ListInsert(LinkList& L, int i, ElemType e) {
    LNode* p = L;
    int j = 0;
    // 寻找第i-1个结点
    while (p && (j < i - 1)) {
        p = p->next;
        j++;
    }
    if (!p || (j > i - 1))
        return ERROR;
    LNode* s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// 单链表的删除
Status ListDelete(LinkList& L, int i, ElemType& e) {
    LNode* p = L;
    int j = 0;
    // 寻找第i个结点，并令p指向其前驱
    while (p->next && (j < i - 1)) {
        p = p->next;
        j++;
    }
    if (!p->next || (j > i - 1))
        return ERROR;
    LNode* q = p->next;
    p->next = q->next;
    e = q->data;
    delete q;
    return OK;
}

// 前插法创建单链表
void CreateList_H(LinkList& L, int n) {
    L = new LNode;
    L->next = nullptr;
    LNode* p;
    while (n--) {
        p = new LNode;
        std::cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

// 后插法创建单链表
void CreateList_R(LinkList& L, int n) {
    L = new LNode;
    L->next = nullptr;
    LNode* r = L;  // 尾指针r指向头结点
    LNode* p;
    while (n--) {
        p = new LNode;
        std::cin >> p->data;
        p->next = nullptr;
        r->next = p;
        r = p;  // 即r = r->next;
    }
}