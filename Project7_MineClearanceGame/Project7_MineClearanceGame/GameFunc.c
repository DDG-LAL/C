#define _CRT_SECURE_NO_WARNINGS 1

#include"GameFunc.h"

void choose(int* p, int a, int b)  //ѡ��ѡ��
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

int inboard(int x, int y)  //�ж�ĳ�������Ƿ��ڷ�Χ��
{
	if ((x >= 0) && (x < X) && (y >= 0) && (y < Y))
		return 1;
	else
		return 0;
}

void initial(int mine[X][Y], char board[X][Y])  //��ʼ��
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
		x = 0 + rand() % 10;  //�����������
		y = 0 + rand() % 10;
		if (mine[x][y] != -1)  //������û����
		{
			mine[x][y] = -1;
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					if ((mine[i][j] != -1) && (inboard(i, j) == 1))  //������ΧһȦ�����������ȫ��+1
						mine[i][j]++;
				}
			}
			n++;  //�����׳ɹ������
		}
	}
}

void test(int mineboard[X][Y])  //��ʾmine��ǰ״̬��������
{
	int i = 0;
	printf("    -");
	for (i = 0; i < X; i++)
		printf("---");
	printf("\n");
	for (i = 0; i < Y; i++)
	{
		printf("%2d  |", Y - i);  //��ӡ������
		int j = 0;
		for (j = 0; j < X; j++)
		{
			printf("%2d ", mineboard[j][Y - i - 1]);  //��ӡ������������
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

void display(char board[X][Y])  //��ʾ��ǰ��Ϸ״̬
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
			printf("%c ", board[j][Y - i - 1]);  //��ӡ�����������(�ڸǻ���ʾ�����)
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

int play(int mine[X][Y], char board[X][Y])  //����һ�β���(ѡ��һ�����꣬�ж���û����)
{
	int x, y;
	while (1)
	{
		printf("��������:(��ʽ:x,y)\n");
		scanf("%d,%d", &x, &y);
		if ((board[x - 1][y - 1] != 'X') || inboard(x - 1, y - 1) == 0)
			printf("\n����Ƿ�\n\n");
		else
			break;
	}
	x--;
	y--;
	int i = 0, j = 0;
	switch (mine[x][y])
	{
	case 0:  //������Χû����
		print0(mine, board, x, y);  
		for (i = 0; i < X; i++)  //���������Χ8���Ƿ�Ҳû����
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
		board[x][y] = 48 + mine[x][y];  //'0'��ASCII��ֵΪ48��mine[x][y]Ϊ��ǰ������Χ������
		break;
	case -1:  //����������
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

int judge(char board[X][Y])  //�ж��Ƿ�ʤ��
{
	int i = 0, j = 0,sum=0;
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			if (board[i][j] == 'X')  //��δɨ�ĸ��ӽ��м���
				sum++;
			if (sum > M)  //��δɨ�ĸ��Ӵ����׵���������δ��ʤ
				return 0;
		}
	}
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)  //��ʤ����ʾ��������
		{
			if (board[i][j] == 'X')
				board[i][j] = '*';
		}
	}
	return 1;
}

void print0(int mine[X][Y], char board[X][Y], int x, int y)  //��������Χû����ʱ������Ĵ�ӡ
{
	int i = 0, j = 0, k = 0;
	for (k = 1; k < X; k++)
	{
		int flag = 0;
		for (i = x - k; i <= x + k; i++)  //������[x][y]Ϊ���ģ��߳��������ӵķ����е�ÿһ��
		{
			for (j = y - k; j <= y + k; j++)  //������[x][y]Ϊ���ģ��߳��������ӵķ����е�ÿһ��
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



