//��������Ϸ
//����main������.c�ļ�:д����������߼������Գ���ʱ����������ѡ�񲿷ַ�֧���в���

#define _CRT_SECURE_NO_WARNINGS 1

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
	initchess(chess);
	menu2();
	int* m = &gamemode;
	choose(m, 1, 2);
	switch (gamemode)
	{
	case 1:
	{
		system("cls");
		human(chess);
		break;
	}
	case 2:
	{
		int dif = 0;
		int* d = &dif;
		menu3();
		choose(d, 1, 2);
		system("cls");
		machine(chess, dif);
		break;
	}
	default:
	{
		printf("\nerr\n");
		system("pause");
		break;
	}
	}
}

int main()
{
	srand((unsigned int)time(NULL));  //�������ʼ��
	int choice ;
	do
	{
		menu1();
		int* c = &choice;
		choose(c, 1, 0);
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
			printf("\nerr\n");
			system("pause");
			break;
		}
		}
	} while (choice);
	return 0;
}