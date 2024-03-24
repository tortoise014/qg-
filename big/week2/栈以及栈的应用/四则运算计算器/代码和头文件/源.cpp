#define _CRT_SECURE_NO_WARNINGS
#include"yuan.h"


int main() {
	char str[100];
	char post[100];
	int i; 
	while (1) {
		printf("\n输入一串中缀表达式：\n");
		gets_s(str);
		if (!check(str))
		{
			printf("请输入正确的符号");
			continue;
		}
		printf("\n对应的后缀表达式：\n");
		change(str, post);
		printf("%s", post);
		printf("\n\n计算后缀表达式：\n");
		printf("%f", cale(post));
	}
	return 0;

	
}