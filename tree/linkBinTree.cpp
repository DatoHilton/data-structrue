#include <iostream>
#include "..\define.h"

// 二叉树的链式存储结构
typedef char TElemType;
typedef struct __BinTreeNode {
    TElemType data;
    struct __BinTreeNode *lchild, *rchild;
} BinTreeNode, *BinTree;

/*
// 定义循环队列，层次遍历时使用
#define MAXSIZE 100
typedef struct {
    __BinTreeNode data[MAXSIZE];
    TElemType front, rear;
} SeqQueue;
*/

// 遍历时的操作
void visit(BinTree T) {
    std::cout << T->data << " ";
}

// 先序遍历
Status preOrderTraverse(BinTree T) {
    if (T == nullptr)
        return OK;
    visit(T);                     // 根
    preOrderTraverse(T->lchild);  // 左
    preOrderTraverse(T->rchild);  // 右
}

// 中序遍历
Status preOrderTraverse(BinTree T) {
    if (T == nullptr)
        return OK;
    preOrderTraverse(T->lchild);  // 左
    visit(T);                     // 根
    preOrderTraverse(T->rchild);  // 右
}

// 后序遍历
Status preOrderTraverse(BinTree T) {
    if (T == nullptr)
        return OK;
    preOrderTraverse(T->lchild);  // 左
    preOrderTraverse(T->rchild);  // 右
    visit(T);                     // 根
}

/*
// 层次遍历
void levelOrder(BinTreeNode* b) {
    BinTreeNode* p;
    SeqQueue* q;
    initQueue(q);             // 初始化队列
    enQueue(q, b);            // 根结点指针入队
    while (!QueueEmpty(q)) {  // 队不为空，则循环
        deQueue(q, p);        // p结点出队
        visit(p);             // 访问p结点
        if (p->lchild != nullptr)
            enQueue(q, p->lchild);  // 有左孩子时则将其入队
        if (p->rchild != nullptr)
            enQueue(q, p->rchild);  // 有右孩子时则将其入队
    }
}
*/

// 先序遍历方式建立二叉树
Status createBinTree(BinTree& T) {
    char ch;
    std::cin >> ch;
    if (ch == '#')
        T = nullptr;
    else {
        if (!(T = new BinTreeNode))
            exit(OVERFLOW);
        T->data = ch;
        createBinTree(T->lchild);  // 构造左子树
        createBinTree(T->rchild);  // 构造右子树
    }
    return OK;
}

// 先序遍历方式复制二叉树
int copy(BinTree T, BinTree& newT) {
    if (T == nullptr) {
        newT = nullptr;
        return 0;
    }
    newT = new BinTreeNode;
    newT->data = T->data;
    copy(T->lchild, newT->lchild);
    copy(T->rchild, newT->rchild);
}

// 计算二叉树的深度
int getDepth(BinTree T) {
    if (T == nullptr)
        return 0;
    int llen = getDepth(T->lchild);
    int rlen = getDepth(T->rchild);
    if (llen > rlen)
        return llen + 1;
    else
        return rlen + 1;
}

// 计算二叉树节点总数
int nodeCount(BinTree T) {
    if (T == nullptr)
        return 0;
    return nodeCount(T->lchild) + nodeCount(T->rchild) + 1;
}

// 计算二叉树叶子结点数
int leafCount(BinTree T) {
    if (T == nullptr)
        return 0;
    if (T->lchild == nullptr && T->rchild == nullptr)
        return 1;
    else
        return leafCount(T->lchild) + leafCount(T->rchild);
}