#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;//节点
typedef struct {
    Node* top;
    int size;
}ListStack;
//初始化
void InitLIstStack(ListStack& L) {
    L.top = NULL;
    L.size = 0;
}
//判断是否为空
bool IsEmpty(ListStack L) {
    if (L.top == NULL) {

        return true;
    }
    return false;
}
//入栈
void Push(ListStack& L, int x) {
    Node* newnode = NULL;
    newnode = (Node*)malloc(sizeof(Node));

    newnode->data = x;
    newnode->next = L.top;
    L.top = newnode;
    L.size++;
}
//出栈,并且展示出去的是什么
int Pop(ListStack& L) {
    if (IsEmpty(L)) {
        printf("没有元素了");
        exit(EXIT_FAILURE);
    }
    int v = L.top->data;
    Node* tmp = L.top;
    L.top = L.top->next;
    free(tmp);
    return v;
}
//查看第一个元素
int peek(ListStack L) {
    if (IsEmpty(L)) {
        printf("空的");
        exit(EXIT_FAILURE);
    }
    int v = L.top->data;
    return v;
}
//查看栈的长度
int stackLength(ListStack L) {
    return L.size;
}
//清空
void clearStack(ListStack& L) {
    while (!IsEmpty(L)) {
        Pop(L);
    }
}
//销毁

void destroyStack(ListStack& L) {
    clearStack(L);
    // 释放栈顶指针
    L.top = NULL;

}
int sum(ListStack L) {
    if (size < 1) {
        return 0;
    }


}
