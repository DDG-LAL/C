//.c文件:写函数实现，一般与.h文件对应命名

#define _CRT_SECURE_NO_WARNINGS 1

#include "GameFunc.h"

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

void initchess(char chess[X][Y])  //初始化棋盘
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
	int i, j, k;
	for (i = 0; i < Y; i++)  //y坐标确定行
	{
		printf("\n %d ", Y - i);
		for (j = 0; j < X; j++)  //x坐标确定列
		{
			printf(" %c |", chess[j][Y - i - 1]);
		}
		printf("\b ");  //打印backspace，删掉多余的"|"
		if (i == Y - 1)
		{
			printf("\n ");
			for (k = 0; k < X; k++)
			{
				printf("   %d", k + 1);
			}
			printf("\n");
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

char chesstype(char arr[])  //选择棋子形状
{
	int tmp = 0;
	char o;
	//getchar:从stdin(标准输入，即键盘输入)中读取一个字符，实际上是读取输入缓冲区中的一个字符
	//getchar返回类型是int(字符的ASCII码值)，若读取时遇到错误或文件结束，则返回EOF(EOF == -1)，即End Of File
	while (1)
	{
		while ((tmp = getchar()) != '\n') //清空输入缓冲区
		{
			;
		}
		printf("输入一个字符以代表[%s]的棋子:", arr);
		o = getchar();
		if ((o == '\n') || (o == '\b') || (o == ' ') || (o == '\r') || (o == '\t') || (o == '\v'))
			printf("\n非法字符，不可用\n\n");
		else
			break;
	}
	return o;
}

void round(char* p1, char* p2, char z1, char z2, char chess[X][Y], char* p, char z, int dif)  //进行一个回合
{
	printf("%s:%c   %s:%c\n\n", p1, z1, p2, z2);
	printf("%s的回合:\n", p);
	printboard(chess);
	switch (dif)  //难度0设为玩家落子，难度1为easy电脑，难度2为hard电脑
	{
	case 0:
	{
		play(chess, z);  //玩家落子
		break;
	}
	case 1:
	{
		easy(chess, z);  //easy电脑落子
		break;
	}
	case 2:
	{
		hard(chess, z, z2);  //hard电脑落子
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
	char winner = '\b';
	if (n < 5)  //双方至少总共下5子才有可能分胜负
		return 0;
	for (i = 0; i < Y; i++)  //判断行
	{
		if (chess[0][i] == ' ')  //该行有一个空格，不可能在此处连成三子，跳过
			continue;
		else if (chess[0][i] == chess[1][i])
		{
			if (chess[0][i] == chess[2][i])
			{
				winner = chess[0][i];  //确定胜方棋子
				flag = 1;
				break;
			}
		}
	}
	if (!flag)
	{
		for (i = 0; i < Y; i++)  //判断列
		{
			if (chess[i][0] == ' ')  //该列有一个空格，不可能在此处连成三子，跳过
				continue;
			else if (chess[i][0] == chess[i][1])
			{
				if (chess[i][0] == chess[i][2])
				{
					winner = chess[i][0];  //确定胜方棋子
					flag = 1;
					break;
				}
			}
		}
	}
	if (!flag)  //判断对角线
	{
		if (chess[1][1] == ' ')  //中点位置为空格，不可能有对角线连成三子，跳过
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
	if (winner == z1)
		return 1;
	else if (winner == z2)
		return 2;
	else if (n == 9)  //平局
		return 3;
	else if (flag == 0)  //未分胜负
		return 0;
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
	char zi0 = chesstype(player[0]);  //确定双方棋子
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
		p = (flag == 1) ? player[0] : player[1];  //本轮的玩家
		z = (flag == 1) ? zi0 : zi1;  //本轮的玩家使用的棋子
		round(player[0], player[1], zi0, zi1, chess, p, z, 0);  //玩家落子
		flag = -flag;
		n++;
		result = judge(chess, zi0, zi1, n);  //判定胜负
		if (result != 0)
			break;
	}
	outcome(result, chess, player[0], player[1], zi0, zi1);  //输出胜负结果
}

void machine(char chess[X][Y], int dif)  //人机模式
{
	int n = 0, flag = 0, result = 0;
	int* f = &flag;
	printf("选择先手的一方:\n1.电脑  2.玩家\n\n");
	choose(f, 1, 2);  //输入选择
	system("cls");
	char player[][5] = { "电脑","玩家" };
	printf("%s为先手\n", player[flag - 1]);
	char zi0 = chesstype(player[0]);  //确定双方棋子
	char zi1 = chesstype(player[1]);
	while (zi0 == zi1)
	{
		printf("\n不能使用相同的棋子\n\n");
		zi1 = chesstype(player[1]);
	}
	system("cls");
	if (flag == 2)  //玩家先手时把flag置为-1
		flag = -1;
	while (1)
	{
		char* p;  //本轮的一方
		char z;  //本轮的一方使用的棋子
		p = (flag == 1) ? player[0] : player[1];
		z = (flag == 1) ? zi0 : zi1;
		if (flag == -1)
			round(player[0], player[1], zi0, zi1, chess, p, z, 0);  //玩家回合
		else
			round(player[0], player[1], zi0, zi1, chess, p, z, dif);  //电脑回合
		n++;
		flag = -flag;
		result = judge(chess, zi0, zi1, n);  //判定胜负
		if (result != 0)
			break;
	}
	outcome(result, chess, player[0], player[1], zi0, zi1);  //输出胜负结果
}

void easy(char chess[X][Y], char z)  //easy人机
{
	int l[9] = { 0 };
	int i = 0, j = 0, ret = -1;
	char* position = &chess[0][0];
	for (i = 0; i < 9; i++)  //i记录空位的位置
	{
		if ((*position == ' ') && (position != &chess[1][1]))  //发现空位的条件
		{
			l[j] = i;  //存下当前空位与chess[0][0]位置的距离
			j++;  //j为s数组l[]中储存的有效元素个数，即空位的个数
		}
		position++;  //指针指向下一个位置
		if (position > &chess[2][2])  //超出棋盘数组范围
			break;
	}
	ret = 0 + rand() % j;  //生成0至j-1中的一个随机数，j为空位数，j-1对应最后一个空位在l[]中的下标
	position = &chess[0][0];  //重置指针
	position += l[ret];
	*position = z;
}

int amax(int a[], int n)  //求数组内最大元素的下标
{
	int i, m = 0;
	for (i = 0; i < n; i++)
		if (a[i] > a[m])
			m = i;
	return m;
}

void hard(char chess[X][Y], char z, char z1)  //hard人机(玩家有机会取胜时会防守玩家，电脑有机会取胜时会主动取胜)
{
	int i = 0, j = 0, k = 0, flag = 0;
	char* p = &chess[0][0];
	for (i = 0; i < 9; i++)  //观察棋盘空位数量
	{
		if (*p == ' ')
			flag++;  //记录棋盘空位数
		p++;
	}
	if ((flag == 8) || (flag == 9) || (flag == 1)) //玩家下一步不可能直接获胜的情况
	{
		if (chess[1][1] == ' ')
		{
			chess[1][1] = z;
			return;
		}
		else
		{
			easy(chess, z);
			return;
		}
	}
	else
	{
		flag = 0;
		for (i = 0; i < X; i++)  //检查对角线1（即/）
		{
			if (chess[i][i] == z1)
				flag++;
			if (chess[i][i] == z)
				flag--;
		}
		if ((flag == 2) || (flag == -2))  //玩家在此线上已有两子(即2)，或电脑在此线上已有两子(即-2)
		{
			for (j = 0; j < X; j++)
				if (chess[j][j] == ' ')
					chess[j][j] = z;
			return;
		}
		flag = 0;
		for (i = 0; i < X; i++)  //检查对角线2（即\）
		{
			if (chess[i][X - i - 1] == z1)
				flag++;
			if (chess[i][X - i - 1] == z)
				flag--;
		}
		if ((flag == 2) || (flag == -2))  //玩家在此线上已有两子(即2)，或电脑在此线上已有两子(即-2)
		{
			for (j = 0; j < X; j++)
				if (chess[j][X - j - 1] == ' ')
					chess[j][X - j - 1] = z;
			return;
		}
		flag = 0;
		int flag1 = 0;
		int x[X] = { 0 }; //落子权重，元素越大，表示越应该在该元素下标对应的列落子
		for (i = 0; i < X; i++)  //检查每一列
		{
			flag = 0;
			for (j = 0; j < Y; j++)
			{
				if (chess[i][j] == z1)
					flag++;
				if (chess[i][j] == z)
					flag--;
			}
			if (flag >= 2)  //玩家在此线上已有两子
			{
				x[i] = 1;
				flag1 = 1;
			}
			if (flag <= -2)  //电脑在此线上已有两子
			{
				x[i] = 2;
				flag1 = 1;
			}
		}
		if (flag1)
		{
			for (i = 0; i < Y; i++)  //在权重最大的一列落子
				if (chess[amax(x, X)][i] == ' ')
					chess[amax(x, X)][i] = z;
			return;
		}
		flag = 0, flag1 = 0;
		int y[Y] = { 0 };  //落子权重，元素越大，表示越应该在该元素下标对应的行落子
		for (j = 0; j < Y; j++)  //检查每一行
		{
			flag = 0;
			for (i = 0; i < X; i++)
			{
				if (chess[i][j] == z1)
					flag++;
				if (chess[i][j] == z)
					flag--;
				
			}
			if (flag >= 2)  //玩家在此线上已有两子
			{
				y[j] = 1;
				flag1 = 1;
			}
			if (flag <= -2)  //电脑在此线上已有两子
			{
				y[j] = 2;
				flag1 = 1;
			}
		}
		if (flag1)
		{
			for (i = 0; i < Y; i++)  //在权重最大的一行落子
				if (chess[i][amax(y, Y)] == ' ')
					chess[i][amax(y, Y)] = z;
			return;
		}
		easy(chess, z);
	}
}