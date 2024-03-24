#pragma once
#include <stdio.h>
#include <stdlib.h>

// 定义节点结构体
typedef struct Node {
    void* data;
    struct Node* next;
    int p;
} Node;

// 定义队列结构体
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;

} Queue;
void LPrint(Queue* Q) {//全部打印
    Node* p1 = Q->front;
    int a;
    while (p1 != NULL) {
        a = p1->p - '0';
        if (a == 1) {
            int* pNum = (int*)(p1->data);
            printf("整数:%d\n", *pNum);
            p1 = p1->next;

        }
        else if (a == 2) {
            char* pChar = (char*)(p1->data);
            printf("字符: %s\n", *pChar);
            p1 = p1->next;
        }
        else if (a == 3) {
            float* pFloat = (float*)(p1->data);
            printf("浮点数: %.2f\n", *pFloat);
            p1 = p1->next;
        }

    }
    printf("没有了");

}
int LengthLQueue(Queue* Q) {//获取长度
    return Q->size;
}



void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// 入队操作
void enqueue(Queue* q, void* data, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->p = x;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
    }
    else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    q->size++;
}
//销毁
void DestoryLQueue(Queue* Q) {//销毁队列
    while (Q->rear != NULL) {
        Node* temp = Q->front;
        void* data = temp->data;
        Q->front = temp->next;
        if (Q->front == NULL) {
            Q->rear = NULL;
        }
        free(temp);
        Q->size--;
    }
    free(Q->rear);
    return;
}

int peek(Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }

    return q->front->p - '0';
}
// 出队操作
void* dequeue(Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    Node* temp = q->front;
    void* data = temp->data;

    q->front = temp->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return data;
}
