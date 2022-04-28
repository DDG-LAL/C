
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#include"GameFunc.h"

void menu1()
{
	system("cls");
	printf("\n************************************\n");
	printf("\n             井字棋游戏             \n");
	printf("\n               1.Play               ");
	printf("\n               0.Exit               \n");
	printf("\n************************************\n\n");
}

void menu2()
{
	system("cls");
	printf("\n************************************\n");
	printf("\n              游戏模式              \n");
	printf("\n               1.双人               ");
	printf("\n               2.人机               \n");
	printf("\n************************************\n\n");
}

void menu3()
{
	system("cls");
	printf("\n************************************\n");
	printf("\n              游戏难度              \n");
	printf("\n               1.简单               ");
	printf("\n               2.困难               \n");
	printf("\n************************************\n\n");
}

void game()
{
	int gamemode = 0;
	char chess[X][Y];
	InitChess(chess);
	menu2();
	printf("输入选择:");
	scanf("%d", &gamemode);
	switch (gamemode)
	{
	case 1:
	{
		system("cls");
		Human(chess);
		break;
	}
	case 2:
	{
		int dif;
		menu3();
		printf("输入选择:");
		scanf("%d", &dif);
		Machine(chess, dif);
		break;
	}
	default:
	{
		printf("\n选择错误\n");
		break;
	}
	}
}

int main()
{
	int choice ;
	do
	{
		menu1();
		printf("输入选择:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
		{
			printf("\n退出游戏\n");
			break;
		}
		default:
		{
			break;
		}
		}
	} while (choice);
	return 0;
}