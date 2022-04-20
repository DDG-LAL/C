#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>


void menu()	//菜单
{
	printf("**************************\n\n");
	printf("          猜数字          \n\n");
	printf("          1.Play          \n");
	printf("          0.Exit          \n\n");
	printf("**************************\n\n");
}

int game()
{
	system("cls");
	int ret = rand() % 200 + 1;  //生成1至200的随机数

	//printf("%d\n", ret);//测试用

	int guess = 0, flag = 0, n = 0, n_MAX = 10;
	printf("\n规则:在1至200的整数中猜1个数，有%d次机会\n\n", n_MAX);
	system("pause");
	while (1)
	{
		n++;
		if (n > n_MAX)
		{
			printf("\n%d次机会用完了，游戏结束\n\n", n_MAX);
			system("pause");
			return 0;
		}
		else
		{
			system("cls");  //清屏
			printf("\n第%d次:请输入猜的数:", n);
			scanf("%d", &guess);
			if (guess == ret)
			{
				printf("\n猜对了!\n\n");
				system("pause");
				return 1;
			}
			else if (guess >= 1 && guess <= 200)
			{
				flag = guess > ret ? 1 : 0;
				switch (flag)  //用flag判断执行状态
				{
				case 1:
				{
					printf("\n猜大了\n\n");
					Sleep(1200);
					break;
				}
				case 0:
				{
					printf("\n猜小了\n\n");
					Sleep(1200);
					break;
				}
				default:
				{
					printf("\nerror\n");
					flag = -1;
					break;
				}
				}
				if (flag == -1)
					break;
				else
					continue;
			}
			else
			{
				printf("\n不在1至200范围内\n");
				continue;
			}
		}
	}
	return -1;
}

void str_output(char arr[][70]) //输出字符数组
{
	printf("%s%s%s%s%s", arr[0], arr[1], arr[2], arr[3], arr[4]);
}

void success()
{
	system("cls");
	int i = 0, j = 0, k = 0, m = 0;
	char arr1[5][70] = { { "|                                                            |\n" },
						 { "|                                                            |\n" },
						 { "|                                                            |\n" },
						 { "|                                                            |\n" },
						 { "|                                                            |\n" } };
	char arr2[5][70] = { { "| y   y    ooo    u   u      w   w   w   iii   nn    n    ** |\n" },
						 { "|  y y    o   o   u   u      w   w   w    i    n n   n    ** |\n" },
						 { "|   y     o   o   u   u       w w w w     i    n  n  n    ** |\n" },
						 { "|   y     o   o   u   u        w   w      i    n   n n       |\n" },
						 { "|   y      ooo     uuu         w   w     iii   n    nn    ** |\n" } };
	char arr3[5][70];
	for (i = 0; i < 5; i++)
		strcpy(arr3[i], arr1[0]);
	int len = strlen(arr1[0]) - 2;  //len=61
	//字符画从左向右移动的效果
	for (i = 0; i < len; i++)  //i:列数
	{
		m = len - 1;
		for (j = i; j > 0; j--)  //j:确定某一列后，遍历(从该列至第一列)的每一列
		{
			for (k = 0; k < 5; k++)  //k:行数
			{
				arr1[k][j] = arr2[k][m];
			}
			m--;
		}
		str_output(arr1);  //
		Sleep(50);
		system("cls");
	}
	str_output(arr2);
	Sleep(2000);
	for (i = 0; i < 3; i++)  //闪烁3次
	{
		system("cls");
		str_output(arr2);
		Sleep(500);
		system("cls");
		str_output(arr3);
		Sleep(500);
	}
	system("cls");
	str_output(arr2);
	printf("\n");
	Sleep(3000);
	system("pause");
	system("cls");
}

void fail()
{
	int i = 0, j = 0, k = 0;
	system("cls");
	Sleep(1000);
	char arr1[] = "                          ";
	char arr2[] = "You  lose         ";
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	printf("\n\n%s\n\n", arr1);
	Sleep(200);
	for (i = 0; i < len2; i++)
	{
		k = 0;
		for (j = len1 - i; j < len1; j++)
		{
			arr1[j] = arr2[k++];
		}
		system("cls");
		printf("\n\n%s\n\n", arr1);
		Sleep(300);
	}
	printf("\n");
	Sleep(3000);
	system("pause");
	system("cls");
}

int main()
{
	srand((unsigned int)time(NULL));  //随机数初始化，整个工程中只需要进行一次
	int choice = 0, outcome = 0;
	do
	{
		menu();
		printf("输入选择: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			outcome = game();
			//printf("%d\n", outcome);//测试
			if (outcome)
				success();
			else if (!outcome)
				fail();
			else
				printf("\nError\n");
			break;
		}
		case 0:
		{
			printf("\n退出游戏\n");
			break;
		}
		default:
		{
			printf("\nERROR\n");
			break;
		}
		}

	} while (choice);
	return 0;
}