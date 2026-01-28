//扫雷游戏

#define _CRT_SECURE_NO_WARNINGS 1

#include"GameFunc.h"

void menu()
{
	system("cls");
	printf("********************************************\n");
	printf("*                                          *\n");
	printf("*                 扫雷游戏                 *\n");
	printf("*                                          *\n");
	printf("*                  1.Play                  *\n");
	printf("*                  0.Exit                  *\n");
	printf("*                                          *\n");
	printf("********************************************\n\n");
}

void game()
{
	int mine[X][Y] = { 0 };  //雷的分布情况，-1为雷，>=0为数量标记
	char board[X][Y];  //用于显示的扫雷区域
	initial_board(board);
	int situation = 0;
	display(board);
	int x1 = 0, y1 = 0;

	while (1)  //避免第一次坐标有雷
	{
		printf("\n输入坐标:(格式:x,y)\n");
		scanf("%d,%d", &x1, &y1);
		if ((board[x1 - 1][y1 - 1] != 'X') || inboard(x1 - 1, y1 - 1) == 0)
			printf("\n坐标非法\n\n");
		else
			break;
	}
	initial_mine(mine, --x1, --y1);
	situation = detect(mine, board, x1, y1);
	system("cls");

	while (situation == 0)
	{
		display(board);
		printf("\n");

		//test(mine);  //显示雷情况，调试用

		situation = play(mine, board);
		system("cls");
	}
	display(board);
	int i = 0, j = 0;
	switch (situation)
	{
	case -1:
		printf("\n");
		for (i = 0; i < X; i++)
		{
			for (j = 0; j < Y; j++)
			{
				if (mine[i][j] == -1)
					board[i][j] = '*';  //显示出所有的雷
			}
		}
		system("pause");
		system("cls");
		display(board);
		printf("\n你输了\n\n");
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
					board[i][j] = ' ';  //清除所有的数字
			}
		}
		system("pause");
		system("cls");
		display(board);
		printf("\n你赢了\n\n");
		break;
	default:
		printf("\nerr\n\n");
		break;
	}
	system("pause");
}

int main()
{
	srand((unsigned int)time(NULL));  //初始化随机数
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
			printf("\n退出游戏\n");
			break;
		default:
			printf("\nChoiceErr\n");
			system("pause");
			break;
		}
	} while (choice);
	return 0;
}