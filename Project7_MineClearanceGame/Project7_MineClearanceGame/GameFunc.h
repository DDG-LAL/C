#pragma once

#define X 10
#define Y 10
#define M 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void choose(int* p, int a, int b);  //选项选择
void initial(int mine[X][Y], char board[X][Y]); //初始化
void display(char board[X][Y]);  //显示当前状态

void test(int board[X][Y]);  //显示当前状态
int play(int mine[X][Y], char board[X][Y]);  //进行一次操作

int judge(char board[X][Y]);  //判断是否胜利

void print0(int mine[X][Y], char board[X][Y], int x, int y);  //

int inboard(int x, int y);  //
