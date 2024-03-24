#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;//�ڵ�
typedef struct {
    Node* top;
    int size;
}ListStack;
//��ʼ��
void InitLIstStack(ListStack& L) {
    L.top = NULL;
    L.size = 0;
}
//�ж��Ƿ�Ϊ��
bool IsEmpty(ListStack L) {
    if (L.top == NULL) {

        return true;
    }
    return false;
}
//��ջ
void Push(ListStack& L, int x) {
    Node* newnode = NULL;
    newnode = (Node*)malloc(sizeof(Node));

    newnode->data = x;
    newnode->next = L.top;
    L.top = newnode;
    L.size++;
}
//��ջ,����չʾ��ȥ����ʲô
int Pop(ListStack& L) {
    if (IsEmpty(L)) {
        printf("û��Ԫ����");
        exit(EXIT_FAILURE);
    }
    int v = L.top->data;
    Node* tmp = L.top;
    L.top = L.top->next;
    free(tmp);
    return v;
}
//�鿴��һ��Ԫ��
int peek(ListStack L) {
    if (IsEmpty(L)) {
        printf("�յ�");
        exit(EXIT_FAILURE);
    }
    int v = L.top->data;
    return v;
}
//�鿴ջ�ĳ���
int stackLength(ListStack L) {
    return L.size;
}
//���
void clearStack(ListStack& L) {
    while (!IsEmpty(L)) {
        Pop(L);
    }
}
//����

void destroyStack(ListStack& L) {
    clearStack(L);
    // �ͷ�ջ��ָ��
    L.top = NULL;

}
int sum(ListStack L) {
    if (size < 1) {
        return 0;
    }


}
