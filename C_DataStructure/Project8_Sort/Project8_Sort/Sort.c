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
	int a[] = { 2,3,1,4,5,0,7,6,8,9,50,30,11,3,6,20,25 };
	int size = sizeof(a) / sizeof(a[0]);
	int reset[] = { 2,3,1,4,5,0,7,6,8,9,50,30,11,3,6,20,25 };
	printarr(a, size);

	printf("  InsertSort: ");
	InsertSort(a, size);
	printarr(a, size);

	memcpy(a, reset, sizeof(int) * size);
	printf("   ShellSort: ");
	ShellSort(a, size);
	printarr(a, size);

	memcpy(a, reset, sizeof(int) * size);
	printf("  SelectSort: ");
	SelectSort(a, size);
	printarr(a, size);

	memcpy(a, reset, sizeof(int) * size);
	printf("    HeapSort: ");
	HeapSort(a, size);
	printarr(a, size);

	memcpy(a, reset, sizeof(int) * size);
	printf("  BubbleSort: ");
	BubbleSort(a, size);
	printarr(a, size);

	memcpy(a, reset, sizeof(int) * size);
	printf("   QuickSort: ");
	QuickSort(a, 0, size - 1);
	printarr(a, size);

	memcpy(a, reset, sizeof(int) * size);
	printf(" NRQuickSort: ");
	QuickSort_NonRecursive(a, 0, size - 1);
	printarr(a, size);

	memcpy(a, reset, sizeof(int) * size);
	printf("TWPQuickSort: ");
	QuickSort_3WayPartition(a, 0, size - 1);
	printarr(a, size);

	memcpy(a, reset, sizeof(int) * size);
	printf("   MergeSort: ");
	MergeSort(a, size);
	printarr(a, size);

	memcpy(a, reset, sizeof(int) * size);
	printf("NRMergeSort1: ");
	MergeSort_NonRecursive1(a, size);
	printarr(a, size);

	memcpy(a, reset, sizeof(int) * size);
	printf("NRMergeSort2: ");
	MergeSort_NonRecursive2(a, size);
	printarr(a, size);
}

void testtime()
{
	const int N = 100000;
	printf("N=%d\n\n", N);
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
	int* a7 = (int*)malloc(sizeof(int) * N);
	if (!a7) return;
	int* a8 = (int*)malloc(sizeof(int) * N);
	if (!a8) return;
	int* a9 = (int*)malloc(sizeof(int) * N);
	if (!a9) return;
	int* a10 = (int*)malloc(sizeof(int) * N);
	if (!a10) return;
	int* a11 = (int*)malloc(sizeof(int) * N);
	if (!a11) return;
	int* a12 = (int*)malloc(sizeof(int) * N);
	if (!a12) return;
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand() + 1000 * rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
		a9[i] = a1[i];
		a10[i] = a1[i];
		a11[i] = a1[i];
		a12[i] = a1[i];
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
	int start7 = clock();
	QuickSort(a6, 0, N - 1);
	int end7 = clock();

	int start8 = clock();
	QuickSort_NonRecursive(a7, 0, N - 1);
	int end8 = clock();
	int start9 = clock();
	QuickSort_NonRecursive(a7, 0, N - 1);
	int end9 = clock();

	int start14 = clock();
	QuickSort_3WayPartition(a12, 0, N - 1);
	int end14 = clock();
	int start15 = clock();
	QuickSort_3WayPartition(a12, 0, N - 1);
	int end15 = clock();

	int start10 = clock();
	MergeSort(a8, N);
	int end10 = clock();

	int start11 = clock();
	MergeSort_Optimized(a9, N);
	int end11 = clock();

	int start12 = clock();
	MergeSort_NonRecursive1(a10, N);
	int end12 = clock();

	int start13 = clock();
	MergeSort_NonRecursive2(a11, N);
	int end13 = clock();



	printf("  InsertSort: %-7dms\n", end1 - start1);
	printf("   ShellSort: %-7dms\n", end2 - start2);
	printf("  SelectSort: %-7dms\n", end3 - start3);
	printf("    HeapSort: %-7dms\n", end4 - start4);
	printf("  BubbleSort: %-7dms\n", end5 - start5);
	printf("   QuickSort: %-7dms\n", end6 - start6);
	printf("   QuickSort: %-7dms (ordered)\n", end7 - start7);
	printf(" NRQuickSort: %-7dms\n", end8 - start8);
	printf(" NRQuickSort: %-7dms (ordered)\n", end9 - start9);
	printf("TWPQuickSort: %-7dms\n", end14 - start14);
	printf("TWPQuickSort: %-7dms (ordered)\n", end15 - start15);
	printf("   MergeSort: %-7dms\n", end10 - start10);
	printf("   MergeSort: %-7dms (optimized)\n", end11 - start11);
	printf("NRMergeSort1: %-7dms\n", end12 - start12);
	printf("NRMergeSort2: %-7dms\n", end13 - start13);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
	free(a9);
	free(a10);
	free(a11);
	free(a12);
}

int main()
{
	srand((size_t)time(NULL));

	testfunc();
	testtime();

	return 0;
}