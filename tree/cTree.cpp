#include <iostream>
#include "..\define.h"

// 树的孩子链表表示法
#define MAX_TREE_SIZE 100
typedef char TElemType;

// 孩子结点结构
typedef struct __CTreeNode {
    int child;                 // 孩子结点下标
    struct __CTreeNode* next;  // 下一个孩子的地址
}* ChildPtr;

// 双亲结点结构
typedef struct {
    TElemType data;
    ChildPtr firstChild;  // 指向第一个孩子
} CTreeBox;               // 孩子链表头指针

// 头指针数组
typedef struct {
    CTreeBox nodes[MAX_TREE_SIZE];
    int r, n;  // 根结点的位置和结点个数
} CTree;