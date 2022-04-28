

#define _CRT_SECURE_NO_WARNINGS 1

#include "GameFunc.h"

#include<stdio.h>
#include<stdlib.h>

void InitChess(char chess[X][Y])  //��ʼ������
{
	int i = 0, j = 0;
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			chess[i][j] = ' ';
		}
	}
}

void printboard(char chess[X][Y])  //��ӡ���̵�ǰ״̬
{
	int i, j;
	for (i = 0; i < Y; i++)  //y����ȷ����
	{
		printf("\n %d ", Y - i);
		for (j = 0; j < X; j++)  //x����ȷ����
		{
			printf(" %c |", chess[j][Y - i - 1]);
		}
		printf("\b ");
		if (i == Y - 1)
		{
			printf("\n    1   2   3\n");
			break;
		}
		printf("\n   ������������");
	}
}

void play(char chess[X][Y], char o)  //�������
{
	int x = 1, y = 1;
	while (1)
	{
		printf("\n�������ӵ�����:(��ʽ:x,y)\n");
		scanf("%d,%d", &x, &y);
		if (x > X || y > Y || x < 1 || y < 1)
			printf("\n���겻�����̷�Χ��\n");
		else if (chess[x - 1][y - 1] != ' ')
			printf("\n��λ����������\n");
		else
		{
			chess[x - 1][y - 1] = o;
			break;
		}
	}
}

char chesstype(char arr[])  //������״
{
	int tmp = 0;
	//getchar:��stdin(��׼���룬����������)�ж�ȡһ���ַ���ʵ�����Ƕ�ȡ���뻺�����е�һ���ַ�
	//getchar����������int(�ַ���ASCII��ֵ)������ȡʱ����������ļ��������򷵻�EOF(EOF == -1)����End Of File
	while ((tmp = getchar()) != '\n') //������뻺����
	{
		;
	}
	printf("����һ���ַ��Դ���[%s]������:",arr);
	char o = getchar();
	return o;
}

void Human(char chess[X][Y])  //˫��ģʽ
{
	char player[][6] = { "���1","���2" };
	printf("���1Ϊ����\n");
	char zi0 = chesstype(player[0]);
	char zi1 = chesstype(player[1]);
	while (zi0 == zi1)
	{
		printf("\n����ʹ����ͬ������\n\n");
		zi1 = chesstype(player[1]);
	}
	int flag = 1, outcome = 0, n = 0;
	system("cls");
	while (1)
	{
		char* p;
		char z;
		p = (flag == 1) ? player[0] : player[1];
		z = (flag == 1) ? zi0 : zi1;
		printf("%s:%c   %s:%c\n\n", player[0], zi0, player[1], zi1);
		printf("%s�Ļغ�:\n",p);
		printboard(chess);
		play(chess, z);
		printboard(chess);
		flag = -flag;
		n++;
		printf("\n");
		system("pause");
		system("cls");
		outcome = judge(chess, zi0, zi1, n);
		if (outcome != 0)
			break;
	}
	printf("%s:%c   %s:%c\n", player[0], zi0, player[1], zi1);
	switch (outcome)
	{
	case 1:
	{
		printboard(chess);
		printf("\n%s��ʤ\n\n", player[0]);
		system("pause");
		break;
	}
	case 2:
	{
		printboard(chess);
		printf("\n%s��ʤ\n\n", player[1]);
		system("pause");
		break;
	}
	case 3:
	{
		printboard(chess);
		printf("\nƽ��\n\n");
		system("pause");
		break;
	}
	default:
	{
		printf("\noutcomeError\n");
		break;
	}
	}
}

int judge(char chess[X][Y], char p1, char p2, int n)  //�ж�ʤ��
{
	int i, flag = 0;
	char winner;
	if (n < 5)
		return 0;
	if (n == 9)
		return 3;
	for (i = 0; i < Y; i++)  //�ж���
	{
		if (chess[0][i] == ' ')
			continue;
		else if (chess[0][i] == chess[1][i])
		{
			if (chess[0][i] == chess[2][i])
			{
				winner = chess[0][i];
				flag = 1;
				break;
			}
		}
	}
	if (!flag)
	{
		for (i = 0; i < Y; i++)  //�ж���
		{
			if (chess[i][0] == ' ')
				continue;
			else if (chess[i][0] == chess[i][1])
			{
				if (chess[i][0] == chess[i][2])
				{
					winner = chess[i][0];
					flag = 1;
					break;
				}
			}
		}
	}
	if (!flag)  //�ж϶Խ���
	{
		if (chess[1][1] == ' ')
			;
		else if (chess[0][0] == chess[1][1])
		{
			if (chess[0][0] == chess[2][2])
			{
				winner = chess[1][1];
				flag = 1;
			}
		}
		else if (chess[0][2] == chess[1][1])
		{
			if (chess[0][2] == chess[2][0])
			{
				winner = chess[1][1];
				flag = 1;
			}
		}
	}
	if (flag == 0)
		return 0;
	else if (winner == p1)
		return 1;
	else if (winner == p2)
		return 2;
	else
	{
		printf("\nJudgeError\n");
		return -1;
	}
}

void Machine(char chess[X][Y], int dif)  //�˻�ģʽ
{
	int n = 0, flag = 0;
	while (flag != 1 && flag != 2)
	{
		system("cls");
		printf("ѡ�����ֵ�һ��:\n1.����  2.���\n\n����ѡ��:");
		scanf("%d", &flag);
		if (flag != 1 && flag != 2)
			printf("\nѡ�����\n");
	}
	system("cls");
	char player[][5] = { "����","���" };
	printf("%sΪ����\n", player[flag - 1]);
	char zi0 = chesstype(player[0]);
	char zi1 = chesstype(player[1]);
	while (zi0 == zi1)
	{
		printf("\n����ʹ����ͬ������\n\n");
		zi1 = chesstype(player[1]);
	}
	system("cls");
	if (flag == 2)
		flag = -1;
	while (1)
	{
		char* p;
		char z;
		p = (flag == 1) ? player[0] : player[1];
		z = (flag == 1) ? zi0 : zi1;
		printf("%s:%c   %s:%c\n\n", player[0], zi0, player[1], zi1);


	}



}