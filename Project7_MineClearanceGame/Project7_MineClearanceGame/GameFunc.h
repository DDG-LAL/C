#pragma once

#define X 10
#define Y 10
#define M 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void choose(int* p, int a, int b);  //ѡ��ѡ��
void initial(int mine[X][Y], char board[X][Y]); //��ʼ��
void display(char board[X][Y]);  //��ʾ��ǰ״̬

void test(int board[X][Y]);  //��ʾ��ǰ״̬
int play(int mine[X][Y], char board[X][Y]);  //����һ�β���

int judge(char board[X][Y]);  //�ж��Ƿ�ʤ��

void print0(int mine[X][Y], char board[X][Y], int x, int y);  //

int inboard(int x, int y);  //
