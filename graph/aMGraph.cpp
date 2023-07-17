#include <iostream>
#include "..\define.h"

// 图的邻接矩阵存储
#define MaxInt 32767        // 表示无穷大
#define MAX_VERTEX_NUM 100  // 最大顶点数
typedef char VerTexType;    // 顶点的数据类型
typedef int ArcType;        // 边的权值类型

typedef struct {
    VerTexType vexs[MAX_VERTEX_NUM];               // 顶点表
    ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  // 邻接矩阵
    int vexNum, arcNum;  // 图的当前顶点数和边数
} AMGraph;               // Adjacency Matrix Graph

// 采用邻接矩阵表示法创建无向网
Status createUDN(AMGraph& G) {
    std::cin >> G.vexNum >> G.arcNum;  // 输入图的总顶点数，总边数
    for (int i = 0; i < G.vexNum; i++)
        std::cin >> G.vexs[i];  // 依次输入顶点的信息

    // 初始化邻接矩阵
    for (int i = 0; i < G.vexNum; i++) {
        for (int j = 0; j < G.vexNum; j++)
            G.arcs[i][j] = MaxInt;
    }
    // 构造邻接矩阵
    for (int k = 0; k < G.arcNum; k++) {
        VerTexType v1, v2;
        ArcType w;
        std::cin >> v1 >> v2 >> w;
        // 寻找顶点的下标
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = G.arcs[i][j];
    }
    return OK;
}

// 在图中查找顶点，返回顶点表的下标，否则返回-1
int LocateVex(AMGraph G, VerTexType v) {
    for (int i = 0; i < G.vexNum; i++) {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}

// 采用邻接矩阵表示图的深度优先搜索遍历
bool visited[MAX_VERTEX_NUM];
void DFS(AMGraph G, int v) {
    std::cout << G.vexs[v];
    // std::cout << v;
    visited[v] = true;
    for (int w = 0; w < G.vexNum; w++) {
        if (G.arcs[v][w] && !visited[w])
            DFS(G, w);
    }
}

// 采用邻接矩阵表示图的广度优先搜索遍历
void BFS(AMGraph& G) {
    for (int v = 0; v < G.vexNum; v++) {
        for (int w = 0; w < G.vexNum; w++) {
            if (G.arcs[v][w] && !visited[w]) {
                std::cout << G.vexs[w];
                visited[w] = 1;
            }
        }
    }
}

// // 按广度优先非递归遍历连通图G
// void BFS(Graph G, int v) {
//     std::cout << v;
//     visited[v] = true;
//     InitQueue(Q);
//     EnQueue(Q, v);
//     while (!QueueEmpty(Q)) {
//         DeQueue(Q, u);
//         for (int w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) {
//             if (!visited[w]) {
//                 std::cout << w;
//                 visited[w] = true;
//                 EnQueue(Q, w);
//             }
//         }
//     }
// }