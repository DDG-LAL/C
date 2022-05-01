//.h文件:写函数声明、引用头文件、定义常量和符号

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define X 3
#define Y 3

void choose(int* p, int a, int b);  //选项选择

void initchess(char chess[X][Y]);  //初始化棋子
void printboard(char chess[X][Y]);  //打印棋盘当前状态
void play(char chess[X][Y], char o);  //玩家落子
char chesstype();  //棋子形状
void round(char* p1, char* p2, char z1, char z2, char chess[X][Y], char* p, char z, int dif);  //进行一个回合

void outcome(int o, char chess[X][Y], char* p1, char* p2, char z1, char z2);  //打印游戏结果
int judge(char chess[X][Y], char p1, char p2, int n);  //判定胜负

void human(char chess[X][Y]);  //双人模式
void machine(char chess[X][Y], int dif);  //人机模式
void easy(char chess[X][Y], char z);  //easy人机

void hard(char chess[X][Y], char z, char z1);  //hard人机