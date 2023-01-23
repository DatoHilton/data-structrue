#include <iostream>
#include "..\define.h"

// 双向链表的存储结构
typedef int ElemType;
typedef struct __DuLNode {
    ElemType data;
    struct __DuLNode *prior, *next;
} DuLNode, *DuLinkList;

// 双向链表的插入
Status ListInsert(DuLinkList& L, int i, ElemType e) {
    // 先取第i个结点并用指针p存放
    DuLNode* p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    // 在第i个位置插入新结点s
    DuLNode* s = new DuLNode;
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
}

// 双向链表的删除
Status ListDelete(DuLinkList& L, int i, ElemType& e) {
    // 先取第i个结点并用指针p存放
    DuLNode* p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    // 删除第i个结点
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    delete p;
    return OK;
}