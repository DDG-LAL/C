//.h�ļ�:д��������������ͷ�ļ������峣���ͷ���

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define X 3
#define Y 3

void choose(int* p, int a, int b);  //ѡ��ѡ��

void initchess(char chess[X][Y]);  //��ʼ������
void printboard(char chess[X][Y]);  //��ӡ���̵�ǰ״̬
void play(char chess[X][Y], char o);  //�������
char chesstype();  //������״
void round(char* p1, char* p2, char z1, char z2, char chess[X][Y], char* p, char z, int dif);  //����һ���غ�

void outcome(int o, char chess[X][Y], char* p1, char* p2, char z1, char z2);  //��ӡ��Ϸ���
int judge(char chess[X][Y], char p1, char p2, int n);  //�ж�ʤ��

void human(char chess[X][Y]);  //˫��ģʽ
void machine(char chess[X][Y], int dif);  //�˻�ģʽ
void easy(char chess[X][Y], char z);  //easy�˻�

void hard(char chess[X][Y], char z, char z1);  //hard�˻�