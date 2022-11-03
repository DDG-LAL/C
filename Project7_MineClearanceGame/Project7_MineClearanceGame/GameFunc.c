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

int inboard(int x, int y)  //判断某个坐标是否在范围内
{
	if ((x >= 0) && (x < X) && (y >= 0) && (y < Y))
		return 1;
	else
		return 0;
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
		x = 0 + rand() % 10;  //生成随机坐标
		y = 0 + rand() % 10;
		if (mine[x][y] != -1)  //坐标上没有雷
		{
			mine[x][y] = -1;
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					if ((mine[i][j] != -1) && (inboard(i, j) == 1))  //在雷周围一圈的数量标记上全部+1
						mine[i][j]++;
				}
			}
			n++;  //生成雷成功后计数
		}
	}
}

void test(int mineboard[X][Y])  //显示mine当前状态，调试用
{
	int i = 0;
	printf("    -");
	for (i = 0; i < X; i++)
		printf("---");
	printf("\n");
	for (i = 0; i < Y; i++)
	{
		printf("%2d  |", Y - i);  //打印纵坐标
		int j = 0;
		for (j = 0; j < X; j++)
		{
			printf("%2d ", mineboard[j][Y - i - 1]);  //打印该坐标的雷情况
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

void display(char board[X][Y])  //显示当前游戏状态
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
			printf("%c ", board[j][Y - i - 1]);  //打印该坐标的雷区(遮盖或显示的情况)
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

int play(int mine[X][Y], char board[X][Y])  //进行一次操作(选择一个坐标，判断有没有雷)
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
	int i = 0, j = 0;
	switch (mine[x][y])
	{
	case 0:  //坐标周围没有雷
		print0(mine, board, x, y);  
		for (i = 0; i < X; i++)  //检测坐标周围8格是否也没有雷
		{
			for (j = 0; j < Y; j++)
			{
				if (board[i][j] == ' ')
					print0(mine, board, i, j);
			}
		}
		break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
		board[x][y] = 48 + mine[x][y];  //'0'的ASCII码值为48，mine[x][y]为当前格子周围的雷数
		break;
	case -1:  //坐标上是雷
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
			if (board[i][j] == 'X')  //对未扫的格子进行计数
				sum++;
			if (sum > M)  //若未扫的格子大于雷的数量，则未获胜
				return 0;
		}
	}
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)  //获胜后显示出所有雷
		{
			if (board[i][j] == 'X')
				board[i][j] = '*';
		}
	}
	return 1;
}

void print0(int mine[X][Y], char board[X][Y], int x, int y)  //当坐标周围没有雷时用特殊的打印
{
	int i = 0, j = 0, k = 0;
	for (k = 1; k < X; k++)
	{
		int flag = 0;
		for (i = x - k; i <= x + k; i++)  //遍历以[x][y]为中心，边长不断增加的方形中的每一列
		{
			for (j = y - k; j <= y + k; j++)  //遍历以[x][y]为中心，边长不断增加的方形中的每一行
			{
				if ((mine[i][j] != -1) && (inboard(i, j)))
				{
					if (mine[i][j] == 0)
						board[i][j] = ' ';
					else
					{
						board[i][j] = 48 + mine[i][j];
						flag = 1;
					}
				}

			}
		}
		if (flag)
			break;
	}
}



