#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>

void InsertSort(int* a, int n); //直接插入排序

void ShellSort(int* a, int n); //希尔排序

void SelectSort(int* a, int n); //直接选择排序

void AdjustDown(int* a, int parent, int size); //向下调整算法
void HeapSort(int* a, int n); //堆排序

void BubbleSort(int* a, int n); //冒泡排序

int Partsort1(int* a, int left, int right); //单次排序(Hoare法)
int Partsort2(int* a, int left, int right); //单次排序(挖坑法)
int Partsort3(int* a, int left, int right); //单次排序(前后指针法)
int Partsort4(int* a, int left, int right); //单次排序(前后指针法)
void QuickSort(int* a, int begin, int end); //快速排序
