#include <iostream>
#include "..\define.h"

// 树的双亲表示法
#define MAX_TREE_SIZE 100
typedef char TElemType;
typedef struct __PTreeNode {
    TElemType data;
    int parent;  // 双亲位置域
} PTreeNode;

typedef struct {
    PTreeNode nodes[MAX_TREE_SIZE];
    int r, n;  // 根结点的位置和结点个数
} PTree;