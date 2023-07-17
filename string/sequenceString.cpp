#include <iostream>
#include "..\define.h"

// 串的顺序存储结构
#define MAXLEN 255
typedef struct __SqString {
    char ch[MAXLEN + 1];  // 不使用数组0号位置
    int length;
} SqString;

// 字符串匹配算法（暴力法）
int index_BF(SqString S, SqString T, int pos) {
    // 从主串的pos位置开始查找，若从头查找令pos==1
    int i = pos, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j])
            i++, j++;  // 主串和子串从头依次匹配字符
        else {
            // 主串和子串指针回溯，重新开始下一次匹配
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length)
        return i - T.length;  // 匹配成功，返回匹配的主串第一个字符的下标
    else
        return 0;  // 匹配失败
}

// 求next数组（优化前）
void get_next(SqString T, int* next) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            i++, j++;
            next[i] = j;
        } else
            j = next[j];
    }
}
// 求next数组（优化后）
void get_nextval(SqString T, int* nextval) {
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            i++, j++;
            if (T.ch[i] != T.ch[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        } else
            j = nextval[j];
    }
}
// 字符串匹配算法（KMP算法）
int index_KMP(SqString S, SqString T, int pos) {
    int* next = new int[T.length + 1];
    get_nextval(T, next);
    // 从主串的pos位置开始查找，若从头查找令pos==1
    int i = pos, j = 1;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j])
            i++, j++;  // 主串和子串从头依次匹配字符
        else
            j = next[j];  // i不变，j后退
    }
    delete[] next;
    if (j > T.length)
        return i - T.length;  // 匹配成功，返回匹配的主串第一个字符的下标
    else
        return 0;  // 匹配失败
}
