
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#include"GameFunc.h"

void menu1()
{
	system("cls");
	printf("\n************************************\n");
	printf("\n             ��������Ϸ             \n");
	printf("\n               1.Play               ");
	printf("\n               0.Exit               \n");
	printf("\n************************************\n\n");
}

void menu2()
{
	system("cls");
	printf("\n************************************\n");
	printf("\n              ��Ϸģʽ              \n");
	printf("\n               1.˫��               ");
	printf("\n               2.�˻�               \n");
	printf("\n************************************\n\n");
}

void menu3()
{
	system("cls");
	printf("\n************************************\n");
	printf("\n              ��Ϸ�Ѷ�              \n");
	printf("\n               1.��               ");
	printf("\n               2.����               \n");
	printf("\n************************************\n\n");
}

void game()
{
	int gamemode = 0;
	char chess[X][Y];
	InitChess(chess);
	menu2();
	printf("����ѡ��:");
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
		printf("����ѡ��:");
		scanf("%d", &dif);
		Machine(chess, dif);
		break;
	}
	default:
	{
		printf("\nѡ�����\n");
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
		printf("����ѡ��:");
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
			printf("\n�˳���Ϸ\n");
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