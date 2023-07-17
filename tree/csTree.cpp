#include <iostream>
#include "..\define.h"

// 树的孩子兄弟表示法
#define MAX_TREE_SIZE 100
typedef char TElemType;

typedef struct __CSNode {
    TElemType data;
    struct __CSNode *firstChild, *nextSibling;
} CSNode, *CSTree;