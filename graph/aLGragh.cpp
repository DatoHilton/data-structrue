#include <iostream>
#include "..\define.h"

// 图的邻接表存储
#define MAX_VERTEX_NUM 100  // 最大顶点数
typedef char VerTexType;    // 顶点的数据类型
typedef int ArcType;        // 边的权值类型
typedef int OtherInfo;      // 和边相关的信息

// 顶点的结点结构
typedef struct VNode {
    VerTexType data;
    ArcNode* firstArc;  // 指向第一条依附该顶点的边的指针
} VNode, AdjList[MAX_VERTEX_NUM];

// 边的结点结构
typedef struct __ArcNode {
    int adjVex;  // 该边所指向的顶点的位置
    struct __ArcNode* nextArc;
    OtherInfo info;
} ArcNode;

// 图的结构定义
typedef struct {
    AdjList vertices;    // vertex的复数，存储所有顶点
    int vexNum, arcNum;  // 图的当前顶点数和弧数
} ALGragh;

// 采用邻接表表示法创建无向网
Status createUDG(ALGragh& G) {
    std::cin >> G.vexNum >> G.arcNum;  // 输入总顶点数，总边数
    // 构造表头结点表
    for (int i = 0; i < G.vexNum; i++) {
        std::cin >> G.vertices[i].data;    // 输入顶点值
        G.vertices[i].firstArc = nullptr;  // 初始化表头结点的指针域
    }
    // 构造邻接表
    for (int k = 0; k < G.arcNum; k++) {
        VerTexType v1, v2;
        std::cin >> v1 >> v2;  // 输入一条边依附的两个顶点
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        ArcNode* p1 = new ArcNode;  // 生成一个新的边结点*p1
        p1->adjVex = j;             // 邻接点序号为j
        p1->nextArc = G.vertices[i].firstArc;
        G.vertices[i].firstArc = p1;  // 将新结点*p1插入顶点vi的边表头部
        ArcNode* p2 = new ArcNode;  // 生成一个新的边结点*p2
        p2->adjVex = i;             // 邻接点序号为i
        p2->nextArc = G.vertices[j].firstArc;
        G.vertices[j].firstArc = p2;  // 将新结点*p2插入顶点vj的边表头部
    }
    return OK;
}

// 在图中查找顶点，返回顶点表的下标，否则返回-1
int LocateVex(ALGragh G, VerTexType v) {
    for (int i = 0; i < G.vexNum; i++) {
        if (G.vertices[i].data == v)
            return i;
    }
    return -1;
}