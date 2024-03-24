#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
typedef struct {//字符
	char* base;
	char* top;
	int size;
}SStack;
typedef struct {//shuzi
	int* base;
	int* top;
	int size;
}NStack;
//shuzi
void InitStackN(NStack* S) {
	S->base = (int*)malloc(10 * sizeof(int));
	if (!S->base)
		return;
	S->top = S->base;
	S->size = 10;
}
//字符初始化
void InitStack(SStack* S) {
	S->base = (char*)malloc(10 * sizeof(char));
	if (!S->base)
		return ;
	S->top = S->base;
	S->size = 10;
}

//入栈
void Push(SStack* S, char x) {
	if (S->top - S->base >= S->size) {
		S->base = (char*)malloc(10 * sizeof(char));
		if (!S->base)
			return;
		S->top = S->base + S->size;
		S->size = S->size + 5;
	}
	*S->top = x;
	S->top++;
}
//shuzi
bool PushNum(NStack* S, double x) {
	if (S->top - S->base >= S->size) {
		S->base = (int*)malloc(10 * sizeof(int));
		if (!S->base)
			return false;
		S->top = S->base + S->size;
		S->size = S->size + 5;
	}
	*S->top = x;
	S->top++;
}
void Pop(SStack* S, char* x) {
	if (S->top == S->base) {
		printf("weikong");
		return;
	}
	S->top--;
	*x = *S->top;

}
//shuzi
bool PopNum(NStack* S, double* x) {
	if (S->top == S->base) {
		printf("weikong");
		return false;
	}
	S->top--;
	*x = *S->top;
	return true;
}
//shuzi
bool isEmpty(NStack* S) {
	if (S->top == S->base) {
		return true;
	}
	return false;
}
bool isEmpty(SStack* S) {
	if (S->top == S->base) {
		return true;
	}
	return false;
}
//检查是否正确
bool check(char* str) {
	int a1=0 ;
	int a2=0 ;
	for (int i = 0; i < strlen(str); i++) {
		if ('(' == str[i]) { a1 += 1; }
		if (')' == str[i]) { a2 += 1; }
		if (!(isdigit(str[i]) || '*' == str[i] || '/' == str[i] || '+' == str[i] || '-' == str[i]||'('==str[i]||')'==str[i])) {

			/*printf("");*/
			return false;
		}
	}
	if (a1 != a2) { return false; }
	return true;
}
bool change(char* str, char* p) {
	SStack S;
	InitStack(&S);   //初始化一个空字符栈
	char x;
	int i;

	int j = 0;
	for (i = 0; i < strlen(str); i++) {
		if (!isdigit(str[i]) || '*' == str[i] || '/' == str[i] || '+' == str[i] || '-' == str[i] || '(' == str[i] || ')' == str[i]) {

			
			return false;
		}
		while (isdigit(str[i])) {
			p[j++] = str[i++];
			if (!isdigit(str[i]))
				p[j++] = ' ';

		}
		if ('(' == str[i]) {
			Push(&S, str[i]);

		}
		if (')' == str[i])
		{
			while ('(' != *(S.top - 1))
			{
				Pop(&S, &x);

				p[j++] = ' ';
			}
			Pop(&S, &x);
		}

		if ('+' == str[i] || '-' == str[i]) {
			while (!isEmpty(&S)) {
				Pop(&S, &x);
				p[j++] = x;
				p[j++] = ' ';
			}
			Push(&S, str[i]);
		}
		if ('*' == str[i] || '/' == str[i]) {
			while (!isEmpty(&S) && '(' != *(S.top - 1) && '+' != *(S.top - 1) && '-' != *(S.top - 1))
			{
				Pop(&S, &x);
				p[j++] = x;
				p[j++] = ' ';
			}
			Push(&S, str[i]);
		}
	}
		while (!isEmpty(&S)) {
			Pop(&S, &x);
			if ('(' != x)
			{
				p[j++] = x;
				p[j++] = ' ';
			}
		}
	
		p[--j] = '\0';
		return true;
	
}
double cale(char* str) {
	NStack S;
	InitStackN(&S);   //初始化
	double x;
	int i;
	char d[100];
	double e;
	int j = 0;
	double a, b;
	for (i = 0; i < strlen(str); i++) {
		{
			int j = 0;
			while (isdigit(str[i]) || '.' == str[i])
			{
				d[j++] = str[i++];
				d[j] = '\0';
				if (!isdigit(str[i]))
				{
					e = atof(d);   //使用atof()将字符串形式的运算数转换为double型数据
					PushNum(&S, e);   //运算数入栈
				}
			}
			switch (str[i])
			{
			case '+':
				PopNum(&S, &b);
				PopNum(&S, &a);
				PushNum(&S, a + b);
				break;
			case '-':
				PopNum(&S, &b);
				PopNum(&S, &a);
				PushNum(&S, a - b);
				break;
			case '*':
				PopNum(&S, &b);
				PopNum(&S, &a);
				PushNum(&S, a * b);
				break;
			case '/':
				PopNum(&S, &b);
				PopNum(&S, &a);
				PushNum(&S, a / b);
				break;
			}
		}
	}
	PopNum(&S, &e);
	return e;
}