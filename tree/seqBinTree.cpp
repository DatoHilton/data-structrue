#include <iostream>
#include "..\define.h"

// 二叉树的顺序存储结构
#define MAXSIZE 100
typedef int TElemType;
// 按满二叉树的结点层次编号，依次存放二叉树中的数据元素
typedef TElemType seqBinTree[MAXSIZE];