

#pragma once

#define X 3
#define Y 3

void InitChess(char chess[X][Y]);  //��ʼ������
void printboard(char chess[X][Y]);  //��ӡ���̵�ǰ״̬
void play(char chess[X][Y], char o);  //�������
char chesstype();  //������״
int judge(char chess[X][Y], char p1, char p2, int n);  //�ж�ʤ��
void Human(char chess[X][Y]);  //˫��ģʽ

void Machine(char chess[X][Y], int dif);  //�˻�ģʽ