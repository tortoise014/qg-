#define _CRT_SECURE_NO_WARNINGS
#include"yuan.h"


int main() {
	char str[100];
	char post[100];
	int i; 
	while (1) {
		printf("\n����һ����׺���ʽ��\n");
		gets_s(str);
		if (!check(str))
		{
			printf("��������ȷ�ķ���");
			continue;
		}
		printf("\n��Ӧ�ĺ�׺���ʽ��\n");
		change(str, post);
		printf("%s", post);
		printf("\n\n�����׺���ʽ��\n");
		printf("%f", cale(post));
	}
	return 0;

	
}