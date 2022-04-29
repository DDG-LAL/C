

#define _CRT_SECURE_NO_WARNINGS 1

#include "GameFunc.h"

#include<stdio.h>
#include<stdlib.h>

void choose(int* p,int a,int b)  //选项选择
{
	while (1)
	{
		printf("输入选择:");
		scanf("%d", p);
		if (*p != a && *p != b)
			printf("\n选择错误\n\n");
		else
			break;
	}
}

void initchess(char chess[X][Y])  //初始化棋子
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

void printboard(char chess[X][Y])  //打印棋盘当前状态
{
	int i, j;
	for (i = 0; i < Y; i++)  //y坐标确定行
	{
		printf("\n %d ", Y - i);
		for (j = 0; j < X; j++)  //x坐标确定列
		{
			printf(" %c |", chess[j][Y - i - 1]);
		}
		printf("\b ");
		if (i == Y - 1)
		{
			printf("\n    1   2   3\n");
			break;
		}
		printf("\n   ——————");
	}
}

void play(char chess[X][Y], char o)  //玩家落子
{
	int x = 1, y = 1;
	while (1)
	{
		printf("\n输入落子的坐标:(格式:x,y)\n");
		scanf("%d,%d", &x, &y);
		if (x > X || y > Y || x < 1 || y < 1)
			printf("\n坐标不在棋盘范围内\n");
		else if (chess[x - 1][y - 1] != ' ')
			printf("\n该位置已有棋子\n");
		else
		{
			chess[x - 1][y - 1] = o;
			break;
		}
	}
}

char chesstype(char arr[])  //棋子形状
{
	int tmp = 0;
	//getchar:从stdin(标准输入，即键盘输入)中读取一个字符，实际上是读取输入缓冲区中的一个字符
	//getchar返回类型是int(字符的ASCII码值)，若读取时遇到错误或文件结束，则返回EOF(EOF == -1)，即End Of File
	while ((tmp = getchar()) != '\n') //清空输入缓冲区
	{
		;
	}
	printf("输入一个字符以代表[%s]的棋子:",arr);
	char o = getchar();
	return o;
}

void round(char* p1, char* p2, char z1, char z2, char chess[X][Y], char* p, char z, int dif)  //进行一个回合
{
	printf("%s:%c   %s:%c\n\n", p1, z1, p2, z2);
	printf("%s的回合:\n", p);
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

void outcome(int o, char chess[X][Y], char* p1, char* p2, char z1, char z2)  //打印游戏结果
{
	printf("%s:%c   %s:%c\n", p1, z1, p2, z2);
	printboard(chess);
	switch (o)
	{
	case 1:
	{
		printf("\n%s获胜\n\n", p1);
		system("pause");
		break;
	}
	case 2:
	{
		printf("\n%s获胜\n\n", p2);
		system("pause");
		break;
	}
	case 3:
	{
		printf("\n平局\n\n");
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

int judge(char chess[X][Y], char z1, char z2, int n)  //判定胜负
{
	int i, flag = 0;
	char winner;
	if (n < 5)
		return 0;
	if (n == 9)
		return 3;
	for (i = 0; i < Y; i++)  //判断行
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
		for (i = 0; i < Y; i++)  //判断列
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
	if (!flag)  //判断对角线
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

void human(char chess[X][Y])  //双人模式
{
	char player[][6] = { "玩家1","玩家2" };
	printf("玩家1为先手\n");
	char zi0 = chesstype(player[0]);
	char zi1 = chesstype(player[1]);
	while (zi0 == zi1)
	{
		printf("\n不能使用相同的棋子\n\n");
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

void machine(char chess[X][Y], int dif)  //人机模式
{
	int n = 0, flag = 0, result = 0;
	int* f = &flag;
	printf("选择先手的一方:\n1.电脑  2.玩家\n\n");
	choose(f, 1, 2);
	system("cls");
	char player[][5] = { "电脑","玩家" };
	printf("%s为先手\n", player[flag - 1]);
	char zi0 = chesstype(player[0]);
	char zi1 = chesstype(player[1]);
	while (zi0 == zi1)
	{
		printf("\n不能使用相同的棋子\n\n");
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

void easy(char chess[X][Y], char z)  //easy人机
{
	int l[9] = { -1 };
	int i = 0, j = 0, ret = -1;
	char* position = &chess[0][0];
	for (i = 0; i < 9; i++)  //记录空位
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
	ret = 0 + rand() % j;  //随机落子
	i = l[j] / Y;
	j = l[j] % X;
	chess[i][j] = z;
}

void hard(char chess[X][Y], char z)  //hard人机
{

}
