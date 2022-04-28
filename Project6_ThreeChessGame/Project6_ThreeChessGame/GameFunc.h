

#pragma once

#define X 3
#define Y 3

void InitChess(char chess[X][Y]);  //初始化棋子
void printboard(char chess[X][Y]);  //打印棋盘当前状态
void play(char chess[X][Y], char o);  //玩家落子
char chesstype();  //棋子形状
int judge(char chess[X][Y], char p1, char p2, int n);  //判定胜负
void Human(char chess[X][Y]);  //双人模式

void Machine(char chess[X][Y], int dif);  //人机模式