#define _CRT_SECURE_NO_WARNINGS 1

#include"SortFunc.h"

void printarr(int* a, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n\n");
}

void testfunc()
{
	int a[] = { 2,3,1,4,5,0,7,6,8,9,50,30 };
	int size = sizeof(a) / sizeof(a[0]);
	int reset[] = { 2,3,1,4,5,0,7,6,8,9,50,30 };
	printarr(a, size);

	printf("InsertSort: ");
	InsertSort(a, size);
	printarr(a, size);

	memcpy(a, reset, sizeof(int) * size);
	printf(" ShellSort: ");
	ShellSort(a, size);
	printarr(a, size);

	memcpy(a, reset, sizeof(int) * size);
	printf("SelectSort: ");
	SelectSort(a, size);
	printarr(a, size);

	memcpy(a, reset, sizeof(int) * size);
	printf("  HeapSort: ");
	HeapSort(a, size);
	printarr(a, size);

	memcpy(a, reset, sizeof(int) * size);
	printf("BubbleSort: ");
	BubbleSort(a, size);
	printarr(a, size);

	memcpy(a, reset, sizeof(int) * size);
	printf(" QuickSort: ");
	QuickSort(a, 0, size - 1);
	printarr(a, size);
}

void testtime()
{
	const int N = 100000;
	printf("N=%d\n", N);
	int* a1 = (int*)malloc(sizeof(int) * N);
	if (!a1) return;
	int* a2 = (int*)malloc(sizeof(int) * N);
	if (!a2) return;
	int* a3 = (int*)malloc(sizeof(int) * N);
	if (!a3) return;
	int* a4 = (int*)malloc(sizeof(int) * N);
	if (!a4) return;
	int* a5 = (int*)malloc(sizeof(int) * N);
	if (!a5) return;
	int* a6 = (int*)malloc(sizeof(int) * N);
	if (!a6) return;
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}

	int start1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int start2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int start3 = clock();
	SelectSort(a3, N);
	int end3 = clock();

	int start4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int start5 = clock();
	BubbleSort(a5, N);
	int end5 = clock();

	int start6 = clock();
	QuickSort(a6, 0, N - 1);
	int end6 = clock();

	printf("InsertSort: %-7dms\n", end1 - start1);
	printf(" ShellSort: %-7dms\n", end2 - start2);
	printf("SelectSort: %-7dms\n", end3 - start3);
	printf("  HeapSort: %-7dms\n", end4 - start4);
	printf("BubbleSort: %-7dms\n", end5 - start5);
	printf(" QuickSort: %-7dms\n", end6 - start6);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

int main()
{
	srand((size_t)time(NULL));

	testfunc();
	//testtime();

	return 0;
}