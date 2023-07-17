#include <iostream>
#include "..\define.h"

// 线索二叉树的链式存储结构
typedef char TElemType;
typedef struct __ThrBinTreeNode {
    TElemType data;
    int ltag, rtag;
    struct __THrBinTreeNode *lchild, *rchild;
} ThrBinTreeNode, *ThrBinTree;