//ɨ����Ϸ

#define _CRT_SECURE_NO_WARNINGS 1

#include"GameFunc.h"

void menu()
{
	system("cls");
	printf("********************************************\n");
	printf("*                                          *\n");
	printf("*                 ɨ����Ϸ                 *\n");
	printf("*                                          *\n");
	printf("*                  1.Play                  *\n");
	printf("*                  0.Exit                  *\n");
	printf("*                                          *\n");
	printf("********************************************\n\n");
}

void game()
{
	int mine[X][Y] = { 0 };  //�׵ķֲ������-1Ϊ�ף�>=0Ϊ�������
	char board[X][Y];  //������ʾ������ɨ������
	int situation = 0;
	initial(mine, board);
	while (situation == 0)
	{
		display(board);
		printf("\n");

		//test(mine);  //��ʾ�������������

		situation = play(mine, board);
		system("cls");
	}
	display(board);
	int i = 0, j = 0;
	switch (situation)
	{
	case -1:
		printf("\n������\n\n");
		break;
	case -2:
		printf("\nerr\n\n");
		break;
	case 1:
		printf("\n");
		for (i = 0; i < X; i++)
		{
			for (j = 0; j < Y; j++)
			{
				if (board[i][j] != '*')
					board[i][j] = ' ';
			}
		}
		system("pause");
		system("cls");
		display(board);
		printf("\n��Ӯ��\n\n");
		break;
	default:
		printf("\nerr\n\n");
		break;
	}
	system("pause");
}

int main()
{
	srand((unsigned int)time(NULL));  //��ʼ�������
	int choice = 0;
	do
	{
		int* c = &choice;
		menu();
		choose(c, 1, 0);
		switch (choice)
		{
		case 1:
			system("cls");
			game();
			break;
		case 0:
			printf("\n�˳���Ϸ\n");
			break;
		default:
			printf("\nChoiceErr\n");
			system("pause");
			break;
		}
	} while (choice);
	return 0;
}