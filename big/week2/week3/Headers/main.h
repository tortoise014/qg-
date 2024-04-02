#pragma once
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

typedef int Elemtype;
typedef struct {
	Elemtype* elem;//����������ʼ��λ��
	int len;//����
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

//����
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
	//�ҵ����ֵ
	int max = A[0];
	for (int i = 0; i < n; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
		}
	}

	int range = max + 1;//���ٿռ������
	int* countArr = (int*)malloc(sizeof(int) * range);//���ٿռ�
	//��ʼ������ȫ��Ϊ0
	memset(countArr, 0, sizeof(int) * range);

	//��ʼ����
	for (int i = 0; i < n; i++)
	{
		countArr[A[i]]++;
	}

	//��ʼ����
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
	}printf("��һ��Ԫ�����ڱ�,����������");
}
//�鲢
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
	fp = fopen(filename, "a"); // ���ļ���д��ģʽ��
	if (fp == NULL) {
		printf("Error opening file.\n");
		return;
	}

	// �����Ա���������д���ļ�
	for (int i = 0; i < ST.len; i++) {
		fprintf(fp, "%d ", ST.elem[i]);
	}

	fclose(fp); // �ر��ļ�
	printf("����ɹ�\n");
}
void read(const char* filename, SStable& ST) {
	FILE* fp;
	int value;
	fp = fopen(filename, "r+"); // ���ļ��Զ�ȡģʽ��
	if (fp == NULL) {
		printf("Error opening file.\n");
		return;
	}

	// �����ȡ�ļ��е����ݵ����Ա���
	while (fscanf(fp, "%d", &value) != EOF) {
		ST.elem[ST.len++] = value;
	}

	fclose(fp); // �ر��ļ�
	printf("����ɹ�\n");
}

void clearFile(const char* filename) {
	FILE* fp;
	fp = fopen(filename, "w"); // ��д��ģʽ���ļ����������ļ�����
	if (fp == NULL) {
		printf("Error opening file.\n");
		return;
	}
	fclose(fp); // �����ر��ļ�
	printf("�����\n");
}
void printFileContent(const char* filename) {
	FILE* file; // �ļ�ָ��
	char buffer[1024]; // ����һ�����������洢��ȡ������

	// ���ļ������ı�ģʽ��ȡ
	file = fopen(filename, "r");
	if (file == NULL) {
		perror("Error opening file");
		return;
	}

	// ѭ����ȡ�ļ�ֱ���ļ�ĩβ
	while (fgets(buffer, sizeof(buffer), file) != NULL) {
		// ��ӡ��ȡ������
		printf("%s", buffer);
	}

	// �ر��ļ�
	fclose(file);
}