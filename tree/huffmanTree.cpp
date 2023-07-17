#include <cstring>
#include <iostream>
#include <vector>
#include "..\define.h"
using namespace std;

// 哈夫曼树的存储结构
typedef struct {
    int weight;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;

// 哈夫曼树构造算法
void createHuffmanTree(HuffmanTree HT, int n) {
    if (n <= 1)
        return;
    int num = 2 * n - 1;       // 数组共2n-1个元素
    HT = new HTNode[num + 1];  // 0号下标未用，HT[num]表示根结点
    // 初始化
    for (int i = 1; i <= num; i++) {
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].parent = 0;
    }
    // 输入权值
    for (int i = 1; i <= n; i++)
        std::cin >> HT[i].weight;
    // 开始构造
    for (int i = n + 1; i <= num; i++) {
        // 在HT[k] (1<=k<=i-1) 中选择两个其双亲域为0，
        // 且权值最小的结点，并返回它们在HT中的序号s1和s2
        int s1, s2;
        Select(HT, i - 1, s1, s2);
        // 删除s1，s2
        HT[s1].parent = i;
        HT[s2].parent = i;
        // s1，s2分别作为i的左右孩子
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        // i的权值为左右孩子权值之和
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

void Select(HuffmanTree& HT, int n, int& s1, int& s2) {
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (HT[i].parent == 0)
            v.push_back(i);
    }
    // 找出权值最小的结点
    auto flag1 = v.begin();
    for (auto it = v.begin() + 1; it != v.end(); it++) {
        if (HT[*it].weight < HT[*flag1].weight)
            flag1 = it;
    }
    s1 = *flag1;
    v.erase(flag1);
    // 找出权值第二小的点
    auto flag2 = v.begin();
    for (auto it = v.begin() + 1; it != v.end(); it++) {
        if (HT[*it].weight < HT[*flag2].weight)
            flag2 = it;
    }
    s2 = *flag2;
}

typedef char** HuffmanCode;
void createHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n) {
    // 从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
    HC = new char*[n + 1];     // 分配n个字符编码的头指针矢量
    char* code = new char[n];  // 分配临时存放编码的动态数组空间
    code[n - 1] = '\0';        // 编码结束符
    for (int i = 1; i <= n; i++) {
        int start = n - 1, c = i, f = HT[i].parent;
        // 从叶子结点开始向上回溯，直到根结点
        while (f) {
            start--;  // 回溯一次start向前指一个位置
            if (HT[f].lchild == c)
                code[start] = '0';  // 结点c是f的左孩子，则生成代码0
            else
                code[start] = '1';  // 结点c是f的右孩子，则生成代码1
            // 继续向上回溯
            c = f;
            f = HT[f].parent;
        }
        // 为第i个字符串编码分配空间
        HC[i] = new char[n - start];
        // 将求得的编码从临时空间code复制到HC的当前行中
        strcpy(HC[i], &code[start]);
    }
    delete[] code;
}