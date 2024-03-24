#define _CRT_SECURE_NO_WARNINGS
#include"main.h"


int main() {
    Queue q;
    
    int a, d, x;
    char c;
    int b = 0;
    while (1) {
        printf("请输入你要的选择\n");
        printf("1.创建队列\n");
        printf("2.入队\n");
        printf("3.出队并且打印\n");
        printf("4.打印全部\n");
        printf("5.获取长度\n");
        printf("6.销毁队列\n");

        scanf("%d", &a);
        switch (a) {
        case 1:
            if (b == 1) {
                printf("已经创建好啦");
                break;
            }
            initQueue(&q);
            printf("已经创建成功\n");
            b = 1;
            break;
        case 2:
            if (b == 0) {
                printf("还没有创建队列哦");
                break;
            }
            system("cls");
            printf("请输入你要的选择\n");
            printf("1.输入一个整数\n");
            printf("2.输入一个小数\n");
            printf("3.输入一个字符串\n");
            scanf("%s", &c);

            if (c == '1') {
                printf("请输入你选择的类型\n");
                scanf("%d", &d);
                enqueue(&q, &d, c);
                printf("1\n");
            }
            if (c == '2') {
                printf("请输入你选择的类型\n");
                scanf("%f", &d);
                enqueue(&q, &d, c);
                printf("2\n");
            }

            if (c == '3') {
                printf("请输入你选择的类型\n");
                scanf("%s", &d);
                enqueue(&q, &d, c);
            }
            if (c != '1' && c != '2'&& c != '3') {
                printf("输错啦!!");

            }
            break;
        case 3:
            if (b == 0) {
                printf("先创建啊");
                break;
            }
            x = peek(&q);

            if (x == 1) {
                int* pNum = (int*)dequeue(&q);
                printf("销毁数字: %d\n", *pNum);
            }
            else if (x == 2) {
                char* pChar = (char*)dequeue(&q);
                printf("销毁字符: %s\n", *pChar);
            }
            else if (x == 3) {
                float* pFloat = (float*)dequeue(&q);
                printf("销毁小数: %.2f\n", *pFloat);
            }
            else {
                printf("出列出了问题");
                break;
            }
            break;
        case 4:
            if (b == 1) {
                LPrint(&q);
            }
            else { printf("先创建啊!"); }
            break;
        case 5:
            if (b == 0) {
                printf("还没有创建");
                break;
            }
            a=LengthLQueue(&q);
            printf("长度为:%d", a);
            break;
        case 6:
            if (b == 0) {
                printf("先创建啊!");
                break;
            }
            DestoryLQueue(&q);
            printf("销毁成功");
            b = 0;
            break;
        default:
            printf("请输入正确的");
            break;
        }
        

    }
    return 0;
}






