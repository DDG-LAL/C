#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include"StackFunc.h"

void InsertSort(int* a, int n); //直接插入排序

void ShellSort(int* a, int n); //希尔排序

void SelectSort(int* a, int n); //直接选择排序

void AdjustDown(int* a, int parent, int size); //向下调整算法
void HeapSort(int* a, int n); //堆排序

void BubbleSort(int* a, int n); //冒泡排序

int GetMidIndex(int* a, int left, int right); //三数取中，对key优化
int Partsort1(int* a, int left, int right); //单次排序(Hoare法)
int Partsort2(int* a, int left, int right); //单次排序(挖坑法)
int Partsort3(int* a, int left, int right); //单次排序(前后指针法)
int Partsort4(int* a, int left, int right); //单次排序(前后指针法)
void QuickSort(int* a, int begin, int end); //快速排序
void QuickSort_NonRecursive(int* a, int begin, int end); //快速排序(非递归，利用栈)
void QuickSort_3WayPartition(int* a, int begin, int end); //快速排序(针对有大量重复数据的优化)

void MergeSort(int* a, int n); //归并排序
void MergeSort_Optimized(int* a, int n); //归并排序(小区间优化)
void MergeSort_NonRecursive1(int* a, int n); //归并排序(非递归)
void MergeSort_NonRecursive2(int* a, int n); //归并排序(非递归)
