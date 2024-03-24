#define _CRT_SECURE_NO_WARNINGS

#include "main.h"


int main() {
    ListStack L;
    InitLIstStack(L);
    char input[100];
    int a;
    int b = 0;
    while (true) {
        printf("请输入要做的操作\n");
        printf("1.入栈\n");
        printf("2.出栈\n");
        printf("3.查看顶部元素\n");
        printf("4.查看栈的长度\n");
        printf("5.清空栈\n");
        printf("6.销毁栈\n");


        

        fgets(input, sizeof(input), stdin);  // 从标准输入读取一行文本

        if (sscanf(input, "%d", &a) != 1) {  // 尝试将输入的字符串转换为整数
            printf("输入无效，请输入数字\n");
            continue;  // 输入无效，重新进行下一次循环
        }
        if (a < 1 || a >6) {
            printf("没有这个选择,请重新选择");
            continue;
        }
        switch (a) {
        case 1:

            while (true) {
                printf("请输入数字");
                scanf("%d", &b);
                if (!(b > -9999999999 && b < 999999999999)) {
                    printf("格式错误请输入数字");
                    continue;
                }

                Push(L, b);
                break;
            }
            break;

        case 2:

            printf("出栈的元素为%d\n", Pop(L));
            break;
        case 3:

            printf("最上层的元素为%d\n", peek(L));
            break;
        case 4:
            printf("栈的长度为%d\n", stackLength(L));
            break;
        case 5:
            clearStack(L);
            printf("栈已经清空");
            break;
        case 6:
            destroyStack(L);
            printf("栈已经销毁");
            break;
        }
    }





}