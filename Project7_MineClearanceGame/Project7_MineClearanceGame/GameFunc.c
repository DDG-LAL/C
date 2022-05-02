#define _CRT_SECURE_NO_WARNINGS 1

#include"GameFunc.h"

void choose(int* p, int a, int b)  //选项选择
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

void initial(int mine[X][Y], char board[X][Y])  //初始化
{
	int i = 0, j = 0;
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			board[i][j] = 'X';
		}
	}
	int n = 0;
	while (n < M)
	{
		int x = 0, y = 0;
		x = rand() % 10;
		y = rand() % 10;
		if (mine[x][y] != -1)
		{
			mine[x][y] = -1;
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					if ((mine[i][j] != -1) && (inboard(i, j) == 1))
						mine[i][j]++;
				}
			}
			n++;
		}
	}
}

void test(int board[X][Y])  //显示mine当前状态，调试用
{
	int i = 0;
	printf("    -");
	for (i = 0; i < X; i++)
		printf("---");
	printf("\n");
	for (i = 0; i < Y; i++)
	{
		printf("%2d  |", Y - i);
		int j = 0;
		for (j = 0; j < X; j++)
		{
			printf("%2d ", board[j][Y - i - 1]);
		}
		printf("\b|\n");
	}
	printf("    -");
	for (i = 0; i < X; i++)
		printf("---");
	printf("\n");
	printf("     ");
	for (i = 0; i < X; i++)
		printf("%2d ", i + 1);
	printf("\n");

}

void display(char board[X][Y])  //显示当前状态
{
	int i = 0;
	printf("    -");
	for (i = 0; i < X; i++)
		printf("--");
	printf("\n");
	for (i = 0; i < Y; i++)
	{
		printf("%2d  |", Y - i);
		int j = 0;
		for (j = 0; j < X; j++)
		{
			printf("%c ", board[j][Y - i - 1]);
		}
		printf("\b|\n");
	}
	printf("    -");
	for (i = 0; i < X; i++)
		printf("--");
	printf("\n");
	printf("     ");
	for (i = 0; i < X; i++)
		printf("%d ", i + 1);
	printf("\n");
}

int play(int mine[X][Y], char board[X][Y])  //进行一次操作
{
	int x, y;
	while (1)
	{
		printf("输入坐标:(格式:x,y)\n");
		scanf("%d,%d", &x, &y);
		if ((board[x - 1][y - 1] != 'X') || inboard(x - 1, y - 1) == 0)
			printf("\n坐标非法\n\n");
		else
			break;
	}
	x--;
	y--;
	switch (mine[x][y])
	{
	case 0:
		print0(mine, board, x, y);
		break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
		board[x][y] = 48 + mine[x][y];
		break;
	case -1:
		board[x][y] = '*';
		return -1;
	default:
		printf("\n\nerr\n\n");
		return -2;
	}
	if (judge(board))
		return 1;
	else
		return 0;
}

int judge(char board[X][Y])  //判断是否胜利
{
	int i = 0, j = 0,sum=0;
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			if (board[i][j] == 'X')
				sum++;
			if (sum > 10)
				return 0;
		}
	}
	return 1;
}

void print0(int mine[X][Y], char board[X][Y], int x, int y)
{
	int i = 0, j = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if ((mine[i][j] != -1) && (inboard(i, j)))
			{
				if (mine[i][j] == 0)
					board[i][j] = ' ';
				else
					board[i][j] = 48 + mine[i][j];
			}
				
		}
	}
	if ((mine[x - 1][y - 1] == 0) && (inboard(x - 1, y - 1) == 1))
		print0(mine, board, x - 1, y - 1);

	if ((mine[x - 1][y + 1] == 0) && (inboard(x - 1, y + 1) == 1))
		print0(mine, board, x - 1, y + 1);

	if ((mine[x + 1][y - 1] == 0) && (inboard(x + 1, y - 1) == 1))
		print0(mine, board, x + 1, y - 1);

	if ((mine[x + 1][y + 1] == 0) && (inboard(x + 1, y + 1) == 1))
		print0(mine, board, x + 1, y + 1);
}

int inboard(int x, int y)
{
	if ((x >= 0) && (x < X) && (y >= 0) && (y < Y))
		return 1;
	else
		return 0;
}