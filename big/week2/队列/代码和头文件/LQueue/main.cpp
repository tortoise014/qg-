#define _CRT_SECURE_NO_WARNINGS
#include"main.h"


int main() {
    Queue q;
    
    int a, d, x;
    char c;
    int b = 0;
    while (1) {
        printf("��������Ҫ��ѡ��\n");
        printf("1.��������\n");
        printf("2.���\n");
        printf("3.���Ӳ��Ҵ�ӡ\n");
        printf("4.��ӡȫ��\n");
        printf("5.��ȡ����\n");
        printf("6.���ٶ���\n");

        scanf("%d", &a);
        switch (a) {
        case 1:
            if (b == 1) {
                printf("�Ѿ���������");
                break;
            }
            initQueue(&q);
            printf("�Ѿ������ɹ�\n");
            b = 1;
            break;
        case 2:
            if (b == 0) {
                printf("��û�д�������Ŷ");
                break;
            }
            system("cls");
            printf("��������Ҫ��ѡ��\n");
            printf("1.����һ������\n");
            printf("2.����һ��С��\n");
            printf("3.����һ���ַ���\n");
            scanf("%s", &c);

            if (c == '1') {
                printf("��������ѡ�������\n");
                scanf("%d", &d);
                enqueue(&q, &d, c);
                printf("1\n");
            }
            if (c == '2') {
                printf("��������ѡ�������\n");
                scanf("%f", &d);
                enqueue(&q, &d, c);
                printf("2\n");
            }

            if (c == '3') {
                printf("��������ѡ�������\n");
                scanf("%s", &d);
                enqueue(&q, &d, c);
            }
            if (c != '1' && c != '2'&& c != '3') {
                printf("�����!!");

            }
            break;
        case 3:
            if (b == 0) {
                printf("�ȴ�����");
                break;
            }
            x = peek(&q);

            if (x == 1) {
                int* pNum = (int*)dequeue(&q);
                printf("��������: %d\n", *pNum);
            }
            else if (x == 2) {
                char* pChar = (char*)dequeue(&q);
                printf("�����ַ�: %s\n", *pChar);
            }
            else if (x == 3) {
                float* pFloat = (float*)dequeue(&q);
                printf("����С��: %.2f\n", *pFloat);
            }
            else {
                printf("���г�������");
                break;
            }
            break;
        case 4:
            if (b == 1) {
                LPrint(&q);
            }
            else { printf("�ȴ�����!"); }
            break;
        case 5:
            if (b == 0) {
                printf("��û�д���");
                break;
            }
            a=LengthLQueue(&q);
            printf("����Ϊ:%d", a);
            break;
        case 6:
            if (b == 0) {
                printf("�ȴ�����!");
                break;
            }
            DestoryLQueue(&q);
            printf("���ٳɹ�");
            b = 0;
            break;
        default:
            printf("��������ȷ��");
            break;
        }
        

    }
    return 0;
}






