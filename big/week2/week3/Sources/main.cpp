#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
int main() {
	SStable ST;
	int choice;
	int a;
	int n;
	int c = 0;
	while (1) {
		printf("\n输入你的选择:\n");
		printf("1. 大数据的\n");
		printf("2. 大量小数据的\n");
		printf("3. 清空文件\n");
		printf("4. 读取\n");
		printf("输入你的选择: ");
		scanf("%d", &a);
		if (!(a > 0 && a < 5)) {



			printf("输错了大哥");
			continue;
		}

		system("cls");
		switch (a) {
		case 1:
			printf("请输入数据大小");
			scanf("%d", &n);
			init(ST, n);
			c = 1;
			break;
		case 2:
			printf("请输入数据次数");
			scanf("%d", &n);
			init(ST, n);
			c = 2;
			break;
		case 3:
			clearFile("file.txt");
			continue;
		case 4:
			
			printFileContent("file.txt");
			printf("没有更多了");
			continue;
		}
		while (1) {
			printf("\n输入你的选择:\n");
			printf("1.插入排序\n");
			printf("2. 快排\n");
			printf("3. 归并\n");
			printf("4. 计数\n");
			scanf("%d", &choice);
			if (choice > 0 && choice < 4) {
				break;
			}
			else {
				printf("输错了大哥");
				continue;
			}

		}
		switch (choice) {
		case 1:
			if (c == 1) {
				InsertSort(ST.elem, n);
				save("file.txt", ST);

			}
			if (c == 2) {
				for (int i = 0; i < n; i++) {
					InsertSort(ST.elem, 100);
					save("file.txt", ST);

				}
			}
			break;
		case 2:
			if (c == 1) {
				QuickSort(ST.elem, 0, n);
				save("file.txt", ST);

			}
			if (c == 2) {
				for (int i = 0; i < n; i++) {
					QuickSort(ST.elem, 0, 100);
					save("file.txt", ST);

				}
			}
			break;
		case 3:
			if (c == 1) {
				MergeSort(ST.elem,0, n);
				save("file.txt", ST);

			}
			if (c == 2) {
				for (int i = 0; i < n; i++) {
					MergeSort(ST.elem, 0,100);
					save("file.txt", ST);

				}
			}
			break;
		case 4:
			if (c == 1) {
				CountSort1(ST.elem, n);
				save("file.txt", ST);

			}
			if (c == 2) {
				for (int i = 0; i < n; i++) {
					CountSort1(ST.elem, 100);
					save("file.txt", ST);

				}
			}
			
			break;
		default:
			printf("Invalid choice. Please enter a number between 1 and 4.\n");
		}
	}









		//	init(ST, 1000);
		//	bubblesort(ST.elem, 10);
		//	


		//Elemtype A[10] = { 64,94,95,79,69,84,18,22,12,78 };

		//init(ST,10000);
		//memcpy(ST.elem, A,sizeof(A));
		//	
		//bubblesort(ST.elem, 10000);
		//插入
		//MergeSort(ST.elem, 0, 999);
		//myprint(ST);
		
		//system("pause");
		//save("file.txt", ST);
		//printFileContent("file.txt");
		//InsertSort(ST.elem, 200000);
		//快排
		//QuickSort(ST.elem, 0, 200000);
		//计数
		//CountSort1(ST.elem,200000);
		//myprint(ST);
		//printFileContent("file.txt");
		//用fread
		//while((c = fgetc(fp))!=EOF) {
		//	printf("%c", c);
		//}
		//char buf[134] = { 0 };
		//fread(buf, sizeof(char), 100, fp);
		//puts(buf);
		//偏移到开头
		//fseek(fp,0,SEEK_SET);
		//fclose(fp);
		//saveListToFile("file.txt", ST);
		//ST.len = 0;
		//int num = ST.elem[0];
		//fwrite(&num, sizeof(int), 1, fp);
		//readListFromFile("file.txt", ST);
		//fclose(fp); // 关闭文件
		//for (int i = 0; i <ST.len; i++) {
		//	printf("%d ", ST.elem[i]);
		//}
		//clearFile("file.txt");
		return 0;
	}
	

