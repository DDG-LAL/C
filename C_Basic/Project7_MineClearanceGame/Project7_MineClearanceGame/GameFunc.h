#pragma once

#define X 10
#define Y 10
#define M 15  //雷的个数

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void choose(int* p, int a, int b);  //选项选择
int inboard(int x, int y);  //判断某个坐标是否在范围内

void initial_board(char board[X][Y]);  //初始化扫雷区域
void initial_mine(int mine[X][Y], int x1, int y1);  //初始化雷的分布

void test(int mineboard[X][Y]);  //显示mine当前状态，调试用
void display(char board[X][Y]);  //显示当前游戏状态

int play(int mine[X][Y], char board[X][Y]);  //进行一次操作
int detect(int mine[X][Y], char board[X][Y], int x, int y);  //检测被选择的坐标及其周围有没有雷
int judge(char board[X][Y]);  //判断是否胜利

void print0(int mine[X][Y], char board[X][Y], int x, int y);  //当坐标周围没有雷时用特殊的打印

void print0_better(int mine[X][Y], char board[X][Y], int x, int y);  //当坐标周围没有雷时用特殊的打印，改良版本