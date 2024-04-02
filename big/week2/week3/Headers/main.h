#pragma once
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

typedef int Elemtype;
typedef struct {
	Elemtype* elem;//储存数据起始的位置
	int len;//长度
}SStable;
void init(SStable& ST, int len) {
	ST.len = len;
	ST.elem = (Elemtype*)malloc(sizeof(Elemtype) * ST.len);
	int i;
	srand(time(NULL));
	for (i = 0; i < ST.len; i++) {
		ST.elem[i] = rand() % 5000;
	}

}
void swap(Elemtype& a, Elemtype& b) {

	Elemtype tmp;
	tmp = a;
	a = b;
	b = tmp;
}

//快排
int partition(Elemtype A[], int low, int hight) {
	Elemtype a = A[low];
	while (low < hight) {
		while (low < hight && A[hight] >= a) {
			--hight;
		}
		A[low] = A[hight];
		while (low < hight && A[low] <= a) {
			++low;
		}
		A[hight] = A[low];


	}
	A[low] = a;
	return low;

}
void CountSort1(Elemtype A[], int n)
{
	//找到最大值
	int max = A[0];
	for (int i = 0; i < n; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
		}
	}

	int range = max + 1;//开辟空间的数量
	int* countArr = (int*)malloc(sizeof(int) * range);//开辟空间
	//初始化数组全部为0
	memset(countArr, 0, sizeof(int) * range);

	//开始计数
	for (int i = 0; i < n; i++)
	{
		countArr[A[i]]++;
	}

	//开始排序
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (countArr[i]--)
		{
			A[j] = i;
			j++;
		}
	}

	free(countArr);
}



void QuickSort(Elemtype A[], int low, int hight) {
	if (low < hight) {
		int a = partition(A, low, hight);
		QuickSort(A, low, a - 1);
		QuickSort(A, a + 1, hight);

	}
}
//64,94,95,79,69,84,18,22,12,78
void InsertSort(Elemtype A[], int n) {
	int i, j;
	for (i = 2; i < n; i++) {

		if (A[i] < A[i - 1]) {
			A[0] = A[i];
			for (j = i - 1; A[0] < A[j]; --j) {
				A[j + 1] = A[j];
			}
			A[j + 1] = A[0];

		}
	}printf("第一个元素是哨兵,不参与排序");
}
//归并
void Merge(Elemtype A[], int low,  int mid,int high) {
	       
	Elemtype* B = (Elemtype*)malloc((high - low + 1) * sizeof(Elemtype));
	int i, j, k;
	for (k = low; k <= high; k++) {
		B[k - low] = A[k];
	}
	for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++) {
		if (B[i - low] <= B[j - low]) {
			A[k] = B[i++ - low];
		}
		else {
			A[k] = B[j++ - low];
		}
	}
	while (i <= mid) {
		A[k++] = B[i++ - low];
	}
	while (j <= high) {
		A[k++] = B[j++ - low];
	}
	free(B);
}

void MergeSort(Elemtype A[], int low,int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(A, low, mid);
		MergeSort(A, mid+1, high);
		Merge(A, low, mid, high);

	}
}
void  bubblesort(Elemtype A[], int n) {
	int i, j, flag;
	flag = 0;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (A[j - 1] > A[j]) {
				swap(A[j - 1], A[j]);
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}
}
void myprint(SStable& ST) {
	for (int i = 0; i < ST.len; i++) {

		printf("%d ", ST.elem[i]);
	}
	printf("\n");
}
void save(const char* filename, SStable& ST) {
	FILE* fp;
	fp = fopen(filename, "a"); // 打开文件以写入模式打开
	if (fp == NULL) {
		printf("Error opening file.\n");
		return;
	}

	// 将线性表的内容逐个写入文件
	for (int i = 0; i < ST.len; i++) {
		fprintf(fp, "%d ", ST.elem[i]);
	}

	fclose(fp); // 关闭文件
	printf("保存成功\n");
}
void read(const char* filename, SStable& ST) {
	FILE* fp;
	int value;
	fp = fopen(filename, "r+"); // 打开文件以读取模式打开
	if (fp == NULL) {
		printf("Error opening file.\n");
		return;
	}

	// 逐个读取文件中的内容到线性表中
	while (fscanf(fp, "%d", &value) != EOF) {
		ST.elem[ST.len++] = value;
	}

	fclose(fp); // 关闭文件
	printf("读入成功\n");
}

void clearFile(const char* filename) {
	FILE* fp;
	fp = fopen(filename, "w"); // 以写入模式打开文件，这会清空文件内容
	if (fp == NULL) {
		printf("Error opening file.\n");
		return;
	}
	fclose(fp); // 立即关闭文件
	printf("清空啦\n");
}
void printFileContent(const char* filename) {
	FILE* file; // 文件指针
	char buffer[1024]; // 创建一个缓冲区来存储读取的数据

	// 打开文件，以文本模式读取
	file = fopen(filename, "r");
	if (file == NULL) {
		perror("Error opening file");
		return;
	}

	// 循环读取文件直到文件末尾
	while (fgets(buffer, sizeof(buffer), file) != NULL) {
		// 打印读取到的行
		printf("%s", buffer);
	}

	// 关闭文件
	fclose(file);
}