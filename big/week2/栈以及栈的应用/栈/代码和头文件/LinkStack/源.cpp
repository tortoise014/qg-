#define _CRT_SECURE_NO_WARNINGS

#include "main.h"


int main() {
    ListStack L;
    InitLIstStack(L);
    char input[100];
    int a;
    int b = 0;
    while (true) {
        printf("������Ҫ���Ĳ���\n");
        printf("1.��ջ\n");
        printf("2.��ջ\n");
        printf("3.�鿴����Ԫ��\n");
        printf("4.�鿴ջ�ĳ���\n");
        printf("5.���ջ\n");
        printf("6.����ջ\n");


        

        fgets(input, sizeof(input), stdin);  // �ӱ�׼�����ȡһ���ı�

        if (sscanf(input, "%d", &a) != 1) {  // ���Խ�������ַ���ת��Ϊ����
            printf("������Ч������������\n");
            continue;  // ������Ч�����½�����һ��ѭ��
        }
        if (a < 1 || a >6) {
            printf("û�����ѡ��,������ѡ��");
            continue;
        }
        switch (a) {
        case 1:

            while (true) {
                printf("����������");
                scanf("%d", &b);
                if (!(b > -9999999999 && b < 999999999999)) {
                    printf("��ʽ��������������");
                    continue;
                }

                Push(L, b);
                break;
            }
            break;

        case 2:

            printf("��ջ��Ԫ��Ϊ%d\n", Pop(L));
            break;
        case 3:

            printf("���ϲ��Ԫ��Ϊ%d\n", peek(L));
            break;
        case 4:
            printf("ջ�ĳ���Ϊ%d\n", stackLength(L));
            break;
        case 5:
            clearStack(L);
            printf("ջ�Ѿ����");
            break;
        case 6:
            destroyStack(L);
            printf("ջ�Ѿ�����");
            break;
        }
    }





}