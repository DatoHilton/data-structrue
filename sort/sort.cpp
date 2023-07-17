#include <iostream>
#include "..\define.h"

// 数据元素类型定义
#define MAXSIZE 20
#define KeyType int

typedef struct {
    KeyType key;  // 关键字域
    // 其他数据项
} RedType;  // Record Type

typedef struct {
    RedType r[MAXSIZE];
    int length;
} SeqList;

// 直接插入排序（扑克牌抓牌）
void Sort_Insert(SeqList& L) {
    int i, j;
    for (i = 2; i <= L.length; i++) {
        if (L.r[i].key < L.r[i - 1].key) {  // 判断下一个数用不用排序
            L.r[0] = L.r[i];                // 复制为哨兵
            for (j = i - 1; L.r[0].key < L.r[j].key; j--)
                L.r[j + 1] = L.r[j];  // 后移
            L.r[j + 1] = L.r[0];      // 插入
        }
    }
}

// 最好的情况：比较n-1次，移动0次
// 最坏的情况：比较(n+2)(n-1)/2次，移动(n+4)(n-1)/2，O(n^2)
// 平均的情况：比较(n+2)(n-1)/4次，移动(n+6)(n-1)/4，O(n^2)

// 折半插入排序
void Sort_BinInsert(SeqList& L) {
    int i, j, low, high, mid;
    for (i = 2; i <= L.length; i++) {
        L.r[0] = L.r[i];  // 复制为哨兵
        low = 1, high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (L.r[0].key < L.r[mid].key)
                high = mid - 1;
            else
                low = mid + 1;
        }
        // 循环结束，high+1为插入位置
        for (j = i - 1; j >= high + 1; j--)
            L.r[j + 1] = L.r[j];  // 后移元素
        L.r[high + 1] = L.r[0];   // 插入
    }
}

// O(n^2)

// 希尔排序
void Sort_ShellInsert(SeqList& L, int dlta[], int t) {
    // 按增量序列dlta[0..t-1]对顺序表L作希尔排序
    for (int k = 0; k < t; k++)
        ShellInsert(L, dlta[k]);  // 一趟增量为dlta[k]的插入排序
}

void ShellInsert(SeqList& L, int dk) {
    // 对顺序表L进行一趟增量为dk的希尔排序，dk为步长因子
    int i, j;
    for (i = dk + 1; i <= L.length; i++) {
        if (L.r[i].key < L.r[i - dk].key) {
            L.r[0] = L.r[i];
            for (j = i - dk; j > 0 && (L.r[0].key < L.r[i].key); j -= dk)
                L.r[j + dk] = L.r[j];
            L.r[j + dk] = L.r[0];
        }
    }
}

// 冒泡排序
void Sort_Bubble(SeqList& L) {
    for (int m = 1; m <= L.length - 1; m++) {
        for (int j = 1; j <= L.length - m; j++) {
            if (L.r[j].key > L.r[j + 1].key) {
                RedType temp = L.r[j];
                L.r[j] = L.r[j + 1];
                L.r[j + 1] = temp;
            }
        }
    }
}

// 改进的冒泡排序
void Sort_Bubble2(SeqList& L) {
    int flag = 1;  // flag作为是否有交换的标记
    for (int m = 1; m <= L.length - 1 && flag == 1; m++) {
        flag = 0;
        for (int j = 1; j <= L.length - m; j++) {
            if (L.r[j].key > L.r[j + 1].key) {
                flag = 1;  // 本趟发生交换，flag置为1
                RedType temp = L.r[j];
                L.r[j] = L.r[j + 1];
                L.r[j + 1] = temp;
            }
        }
    }
}

// n个记录，总共需要n-1趟
// 第m趟需要比较n-m次
// 最好的情况：比较次数：n-1次，移动次数：0次
// 最坏的情况：比较次数：n(n-1)/2次，移动次数：3n(n-1)/2次

// 快速排序
void Sort_Quick(SeqList& L, int low, int high) {
    if (low < high) {  // 长度大于1
        int pivotLoc = Partition(L, low, high);
        // 将L.r[low..high]一分为二，pivotLoc为枢轴元素排好序的位置
        Sort_Quick(L, low, pivotLoc - 1);
        Sort_Quick(L, pivotLoc - 1, high);
    }
}

int Partition(SeqList& L, int low, int high) {
    L.r[0] = L.r[low];
    int pivotKey = L.r[low].key;
    while (low < high) {
        while (low < high && L.r[high].key >= pivotKey)
            high--;
        L.r[low] = L.r[high];
        while (low < high && L.r[high].key <= pivotKey)
            low++;
        L.r[high] = L.r[low];
    }
    L.r[low] = L.r[0];
    return low;
}

// 时间复杂度：O(nlogn)
// Sort_Quick()：O(logn)
// Partition()：O(n)
// 空间复杂度：O(logn)

// 简单选择排序
void Sort_Select(SeqList& L) {
    for (int i = 1; i < L.length; i++) {
        int k = i;
        for (int j = i + 1; j <= L.length; j++) {
            if (L.r[j].key < L.r[k].key)
                k = j;  // 记录最小值的位置
        }
        if (k != i) {  // 交换
            RedType temp = L.r[i];
            L.r[i] = L.r[k];
            L.r[k] = temp;
        }
    }
}

// 最好的情况：比较次数：n(n-1)/2次，移动次数：0次
// 最坏的情况：比较次数：n(n-1)/2次，移动次数：3(n-1)次
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)

// 选择排序-堆排序
// 筛选过程算法：调整R[s]的关键字，使R[s..m]成为一个大根堆
void HeapAdjust(int R[], int s, int m) {
    int rc = R[s];
    // 沿key较大的孩子结点向下筛选
    for (int j = 2 * s; j <= m; j *= 2) {
        if (j < m && R[j] < R[j + 1])  // j为key较大的记录的下标
            j++;
        if (rc > R[j])
            break;
        R[s] = R[j], s = j;  // rc插入在s上
    }
    R[s] = rc;
}

// 堆排序算法
void Sort_Heap(int R[], int n) {  // 对R[1]到R[n]进行堆排序
    for (int i = n / 2; i >= 1; i--)
        HeapAdjust(R, i, n);  // 建初始堆
    for (int i = n; i > 1; i--) {
        // 根与最后一个元素交换
        int temp = R[1];
        R[1] = R[i];
        R[i] = temp;
        HeapAdjust(R, 1, i - 1);  // 对R[1]到R[i-1]重新建堆
    }
}

// 时间复杂度：O(nlogn)

// 归并排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)

// 基数排序（桶排序）：分配+收集
// 时间效率：O(k*(n+m))
// k：关键字个数，m：关键字取值范围为m个值
// 空间效率：O(n+m)