//猜数字游戏

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>


void menu()	 //菜单
{
	printf("**************************\n\n");
	printf("          猜数字          \n\n");
	printf("          1.Play          \n");
	printf("          0.Exit          \n\n");
	printf("**************************\n\n");
}

int game()  //猜数字
{
	system("cls");  //system()用于执行系统命令，cls是清屏操作，system函数需要stdlib.h
	//生成1至200的随机数
	//rand用于生成随机数，需要stdlib.h
	int ret = rand() % 200 + 1;  //rand返回值是int类型，返回的是0至0x7fff中的随机整数(0x7fff==32767)

	//printf("%d\n", ret);  //测试用

	int guess = 0, flag = 0, n = 0, n_MAX = 10;  //n_MAX是机会次数，理论上用二分法在8次之内能试出答案
	printf("\n规则:在1至200的整数中猜1个数，有%d次机会\n\n", n_MAX);
	system("pause");  //pause 是暂停操作，cmd窗口中会显示"按任意键继续"
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
			system("cls");
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
				switch (flag)  //用flag判断状态
				{
				case 1:
				{
					printf("\n猜大了\n\n");
					Sleep(1200);  //Sleep用于定时休眠，单位是ms，需要windows.h
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

void str_output(char arr[][70])  //输出二维字符数组
{
	printf("%s%s%s%s%s", arr[0], arr[1], arr[2], arr[3], arr[4]);
}

void success()  //成功之后输出"YOU WIN!"字符画
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
						 { "|   y      ooo     uuu         w   w     iii   n    nn    ** |\n" } };  //you win
	char arr3[5][70];
	for (i = 0; i < 5; i++)  //strcpy就是string copy，将字符串（后）赋值给字符数组（前），需要string.h，返回值是被赋值的字符数组的起始地址
		strcpy(arr3[i], arr1[0]);  
	int len = strlen(arr1[0]) - 2;  //len=61
	//字符画从左向右移动的效果
	//每次将arr2中右边的j列赋给arr1，并j++、清屏、打印，进行i次，形成从左向右移动的效果
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
		str_output(arr1);  
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

void fail()  //失败后输出"You lose"字符串
{
	int i = 0, j = 0, k = 0;
	system("cls");
	Sleep(1000);
	char arr1[] = "                          ";
	char arr2[] = "You  lose         ";
	int len1 = strlen(arr1);  //strlen就是string length，求字符串长度(求长度时不计算字符串末尾的'\0')，需要string.h
	int len2 = strlen(arr2);
	printf("\n\n%s\n\n", arr1);
	Sleep(200);
	//字符串从右向左移动的效果
	//每次将arr2中左边的j个字符赋给arr1，并j++、清屏、打印，进行len2次，形成从右向左移动的效果
	for (i = 0; i < len2; i++)  //i:arr2的字符个数
	{
		k = 0;
		for (j = len1 - i; j < len1; j++)  //j:确定某个字符的位置后，遍历arr2中(从该字符至最后一个字符)的每个位置
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
	//time函数用于获取时间戳，需要time.h，返回值是time_t类型(是一种整型)
	//srand用于为rand函数设置随机数"种子"，srand函数需要stdlib.h，参数应为unsigned int类型，因此对time的返回值使用强制类型转换(unsigned int)
	//在调用rand之前必须先调用一次srand，否则生成的随机数会不够随机
	//多次调用srand也会导致不够随机
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
			if (outcome)  //根据游戏结果决定输出
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