#pragma once

#define X 10
#define Y 10
#define M 10  //�׵ĸ���

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void choose(int* p, int a, int b);  //ѡ��ѡ��
int inboard(int x, int y);  //�ж�ĳ�������Ƿ��ڷ�Χ��

void initial(int mine[X][Y], char board[X][Y]); //��ʼ��
void test(int mineboard[X][Y]);  //��ʾmine��ǰ״̬��������
void display(char board[X][Y]);  //��ʾ��ǰ��Ϸ״̬

int play(int mine[X][Y], char board[X][Y]);  //����һ�β���
int judge(char board[X][Y]);  //�ж��Ƿ�ʤ��

void print0(int mine[X][Y], char board[X][Y], int x, int y);  //��������Χû����ʱ������Ĵ�ӡ

void print0_better(int mine[X][Y], char board[X][Y], int x, int y);  //��������Χû����ʱ������Ĵ�ӡ�������汾