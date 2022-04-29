

#define _CRT_SECURE_NO_WARNINGS 1

#include "GameFunc.h"

#include<stdio.h>
#include<stdlib.h>

void choose(int* p,int a,int b)  //ѡ��ѡ��
{
	while (1)
	{
		printf("����ѡ��:");
		scanf("%d", p);
		if (*p != a && *p != b)
			printf("\nѡ�����\n\n");
		else
			break;
	}
}

void initchess(char chess[X][Y])  //��ʼ������
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

void round(char* p1, char* p2, char z1, char z2, char chess[X][Y], char* p, char z, int dif)  //����һ���غ�
{
	printf("%s:%c   %s:%c\n\n", p1, z1, p2, z2);
	printf("%s�Ļغ�:\n", p);
	printboard(chess);
	switch (dif)
	{
	case 0:
	{
		play(chess, z);
		break;
	}
	case 1:
	{
		easy(chess, z);
		break;
	}
	case 2:
	{
		hard(chess, z);
		break;
	}
	default:
	{
		printf("\ndiferror\n\n");
		break;
	}
	}
	printboard(chess);
	printf("\n");
	system("pause");
	system("cls");
}

void outcome(int o, char chess[X][Y], char* p1, char* p2, char z1, char z2)  //��ӡ��Ϸ���
{
	printf("%s:%c   %s:%c\n", p1, z1, p2, z2);
	printboard(chess);
	switch (o)
	{
	case 1:
	{
		printf("\n%s��ʤ\n\n", p1);
		system("pause");
		break;
	}
	case 2:
	{
		printf("\n%s��ʤ\n\n", p2);
		system("pause");
		break;
	}
	case 3:
	{
		printf("\nƽ��\n\n");
		system("pause");
		break;
	}
	default:
	{
		printf("\noutcomeError\n\n");
		system("pause");
		break;
	}
	}
}

int judge(char chess[X][Y], char z1, char z2, int n)  //�ж�ʤ��
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
	else if (winner == z1)
		return 1;
	else if (winner == z2)
		return 2;
	else
	{
		printf("\nJudgeError\n");
		return -1;
	}
}

void human(char chess[X][Y])  //˫��ģʽ
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
	int flag = 1, result = 0, n = 0;
	system("cls");
	while (1)
	{
		char* p;
		char z;
		p = (flag == 1) ? player[0] : player[1];
		z = (flag == 1) ? zi0 : zi1;
		round(player[0], player[1], zi0, zi1, chess, p, z, 0);
		flag = -flag;
		n++;
		result = judge(chess, zi0, zi1, n);
		if (result != 0)
			break;
	}
	outcome(result, chess, player[0], player[1], zi0, zi1);
}

void machine(char chess[X][Y], int dif)  //�˻�ģʽ
{
	int n = 0, flag = 0, result = 0;
	int* f = &flag;
	printf("ѡ�����ֵ�һ��:\n1.����  2.���\n\n");
	choose(f, 1, 2);
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
		if (flag == -1)
			round(player[0], player[1], zi0, zi1, chess, p, z, 0);
		else
			round(player[0], player[1], zi0, zi1, chess, p, z, dif);
		n++;
		flag = -flag;
		result = judge(chess, zi0, zi1, n);
		if (result != 0)
			break;
	}
	outcome(result, chess, player[0], player[1], zi0, zi1);
}

void easy(char chess[X][Y], char z)  //easy�˻�
{
	int l[9] = { -1 };
	int i = 0, j = 0, ret = -1;
	char* position = &chess[0][0];
	for (i = 0; i < 9; i++)  //��¼��λ
	{
		if ((*position == ' ') && (i != 4))
		{
			l[j] = i;
			position++;
			j++;
		}
		else
			position++;
		if (position == &chess[2][2])
			break;
	}
	ret = 0 + rand() % j;  //�������
	i = l[j] / Y;
	j = l[j] % X;
	chess[i][j] = z;
}

void hard(char chess[X][Y], char z)  //hard�˻�
{

}
