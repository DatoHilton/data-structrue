#include <iostream>
#include "..\define.h"

// 数据元素类型定义
#define KeyType int

typedef struct {
    KeyType key;  // 关键字域
    // 其他域
} ElemType;

// 顺序表结构类型定义
typedef struct {
    ElemType* R;  // 表基址
    int length;   // 表长
} SSTable;        // Sequential Search Table

// 顺序查找
int Search_Seq(SSTable ST, KeyType key) {
    ST.R[0].key = key;  // 监视哨
    int i;
    for (i = ST.length; ST.R[i].key != key; i--)
        ;
    return i;
}

// 查找第i个元素：比较n-i+1次
// 查找失败：比较n+1次
// ASL=(n+1)/2
// 时间复杂度：O(n)
// 空间复杂度：O(1)

// 二分查找（非递归算法）
int Search_Bin(SSTable ST, KeyType key) {
    int low = 1, high = ST.length, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (ST.R[mid].key == key)
            return mid;
        else if (key < ST.R[mid].key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;  // 找不到
}

// 二分查找（递归算法）
int Search_Bin_Rec(SSTable ST, KeyType key, int low, int high) {
    if (low > high)
        return 0;  // 找不到
    int mid = (low + high) / 2;
    if (key == ST.R[mid].key)
        return mid;
    else if (key > ST.R[mid].key)
        return Search_Bin_Rec(ST, key, mid + 1, high);  // 递归在右半区间查找
    else
        return Search_Bin_Rec(ST, key, low, mid - 1);  // 递归在左半区间查找
}

// ASL约等于log(n+1)-1 (n>50)
// 时间复杂度：O(logn)

// 分块查找
// ASL约等于log(n/s+1)+s/2