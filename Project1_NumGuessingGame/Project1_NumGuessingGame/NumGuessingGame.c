//��������Ϸ

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>


void menu()	 //�˵�
{
	printf("**************************\n\n");
	printf("          ������          \n\n");
	printf("          1.Play          \n");
	printf("          0.Exit          \n\n");
	printf("**************************\n\n");
}

int game()  //������
{
	system("cls");  //system()����ִ��ϵͳ���cls������������system������Ҫstdlib.h
	//����1��200�������
	//rand�����������������Ҫstdlib.h
	int ret = rand() % 200 + 1;  //rand����ֵ��int���ͣ����ص���0��0x7fff�е��������(0x7fff==32767)

	//printf("%d\n", ret);  //������

	int guess = 0, flag = 0, n = 0, n_MAX = 10;  //n_MAX�ǻ���������������ö��ַ���8��֮�����Գ���
	printf("\n����:��1��200�������в�1��������%d�λ���\n\n", n_MAX);
	system("pause");  //pause ����ͣ������cmd�����л���ʾ"�����������"
	while (1)
	{
		n++;
		if (n > n_MAX)
		{
			printf("\n%d�λ��������ˣ���Ϸ����\n\n", n_MAX);
			system("pause");
			return 0;
		}
		else
		{
			system("cls");
			printf("\n��%d��:������µ���:", n);
			scanf("%d", &guess);
			if (guess == ret)
			{
				printf("\n�¶���!\n\n");
				system("pause");
				return 1;
			}
			else if (guess >= 1 && guess <= 200)
			{
				flag = guess > ret ? 1 : 0;
				switch (flag)  //��flag�ж�״̬
				{
				case 1:
				{
					printf("\n�´���\n\n");
					Sleep(1200);  //Sleep���ڶ�ʱ���ߣ���λ��ms����Ҫwindows.h
					break;
				}
				case 0:
				{
					printf("\n��С��\n\n");
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
				printf("\n����1��200��Χ��\n");
				continue;
			}
		}
	}
	return -1;
}

void str_output(char arr[][70])  //�����ά�ַ�����
{
	printf("%s%s%s%s%s", arr[0], arr[1], arr[2], arr[3], arr[4]);
}

void success()  //�ɹ�֮�����"YOU WIN!"�ַ���
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
	for (i = 0; i < 5; i++)  //strcpy����string copy�����ַ������󣩸�ֵ���ַ����飨ǰ������Ҫstring.h������ֵ�Ǳ���ֵ���ַ��������ʼ��ַ
		strcpy(arr3[i], arr1[0]);  
	int len = strlen(arr1[0]) - 2;  //len=61
	//�ַ������������ƶ���Ч��
	//ÿ�ν�arr2���ұߵ�j�и���arr1����j++����������ӡ������i�Σ��γɴ��������ƶ���Ч��
	for (i = 0; i < len; i++)  //i:����
	{
		m = len - 1;
		for (j = i; j > 0; j--)  //j:ȷ��ĳһ�к󣬱���(�Ӹ�������һ��)��ÿһ��
		{
			for (k = 0; k < 5; k++)  //k:����
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
	for (i = 0; i < 3; i++)  //��˸3��
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

void fail()  //ʧ�ܺ����"You lose"�ַ���
{
	int i = 0, j = 0, k = 0;
	system("cls");
	Sleep(1000);
	char arr1[] = "                          ";
	char arr2[] = "You  lose         ";
	int len1 = strlen(arr1);  //strlen����string length�����ַ�������(�󳤶�ʱ�������ַ���ĩβ��'\0')����Ҫstring.h
	int len2 = strlen(arr2);
	printf("\n\n%s\n\n", arr1);
	Sleep(200);
	//�ַ������������ƶ���Ч��
	//ÿ�ν�arr2����ߵ�j���ַ�����arr1����j++����������ӡ������len2�Σ��γɴ��������ƶ���Ч��
	for (i = 0; i < len2; i++)  //i:arr2���ַ�����
	{
		k = 0;
		for (j = len1 - i; j < len1; j++)  //j:ȷ��ĳ���ַ���λ�ú󣬱���arr2��(�Ӹ��ַ������һ���ַ�)��ÿ��λ��
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
	//time�������ڻ�ȡʱ�������Ҫtime.h������ֵ��time_t����(��һ������)
	//srand����Ϊrand�������������"����"��srand������Ҫstdlib.h������ӦΪunsigned int���ͣ���˶�time�ķ���ֵʹ��ǿ������ת��(unsigned int)
	//�ڵ���rand֮ǰ�����ȵ���һ��srand���������ɵ�������᲻�����
	//��ε���srandҲ�ᵼ�²������
	srand((unsigned int)time(NULL));  //�������ʼ��������������ֻ��Ҫ����һ��
	int choice = 0, outcome = 0;
	do
	{
		menu();
		printf("����ѡ��: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			outcome = game();
			if (outcome)  //������Ϸ����������
				success();
			else if (!outcome)
				fail();
			else
				printf("\nError\n");
			break;
		}
		case 0:
		{
			printf("\n�˳���Ϸ\n");
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