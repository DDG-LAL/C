//.c�ļ�:д����ʵ�֣�һ����.h�ļ���Ӧ����

#define _CRT_SECURE_NO_WARNINGS 1

#include "GameFunc.h"

void choose(int* p,int a,int b)  //ѡ��ѡ��
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

void initchess(char chess[X][Y])  //��ʼ������
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

void printboard(char chess[X][Y])  //��ӡ���̵�ǰ״̬
{
	int i, j, k;
	for (i = 0; i < Y; i++)  //y����ȷ����
	{
		printf("\n %d ", Y - i);
		for (j = 0; j < X; j++)  //x����ȷ����
		{
			printf(" %c |", chess[j][Y - i - 1]);
		}
		printf("\b ");  //��ӡbackspace��ɾ�������"|"
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
		printf("\n   ������������");
	}
}

void play(char chess[X][Y], char o)  //�������
{
	int x = 1, y = 1;
	while (1)
	{
		printf("\n�������ӵ�����:(��ʽ:x,y)\n");
		scanf("%d,%d", &x, &y);
		if (x > X || y > Y || x < 1 || y < 1)
			printf("\n���겻�����̷�Χ��\n");
		else if (chess[x - 1][y - 1] != ' ')
			printf("\n��λ����������\n");
		else
		{
			chess[x - 1][y - 1] = o;
			break;
		}
	}
}

char chesstype(char arr[])  //ѡ��������״
{
	int tmp = 0;
	char o;
	//getchar:��stdin(��׼���룬����������)�ж�ȡһ���ַ���ʵ�����Ƕ�ȡ���뻺�����е�һ���ַ�
	//getchar����������int(�ַ���ASCII��ֵ)������ȡʱ����������ļ��������򷵻�EOF(EOF == -1)����End Of File
	while (1)
	{
		while ((tmp = getchar()) != '\n') //������뻺����
		{
			;
		}
		printf("����һ���ַ��Դ���[%s]������:", arr);
		o = getchar();
		if ((o == '\n') || (o == '\b') || (o == ' ') || (o == '\r') || (o == '\t') || (o == '\v'))
			printf("\n�Ƿ��ַ���������\n\n");
		else
			break;
	}
	return o;
}

void round(char* p1, char* p2, char z1, char z2, char chess[X][Y], char* p, char z, int dif)  //����һ���غ�
{
	printf("%s:%c   %s:%c\n\n", p1, z1, p2, z2);
	printf("%s�Ļغ�:\n", p);
	printboard(chess);
	switch (dif)  //�Ѷ�0��Ϊ������ӣ��Ѷ�1Ϊeasy���ԣ��Ѷ�2Ϊhard����
	{
	case 0:
	{
		play(chess, z);  //�������
		break;
	}
	case 1:
	{
		easy(chess, z);  //easy��������
		break;
	}
	case 2:
	{
		hard(chess, z, z2);  //hard��������
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

void outcome(int o, char chess[X][Y], char* p1, char* p2, char z1, char z2)  //��ӡ��Ϸ���
{
	printf("%s:%c   %s:%c\n", p1, z1, p2, z2);
	printboard(chess);
	switch (o)
	{
	case 1:
	{
		printf("\n%s��ʤ\n\n", p1);
		system("pause");
		break;
	}
	case 2:
	{
		printf("\n%s��ʤ\n\n", p2);
		system("pause");
		break;
	}
	case 3:
	{
		printf("\nƽ��\n\n");
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

int judge(char chess[X][Y], char z1, char z2, int n)  //�ж�ʤ��
{
	int i, flag = 0;
	char winner = '\b';
	if (n < 5)  //˫�������ܹ���5�Ӳ��п��ܷ�ʤ��
		return 0;
	for (i = 0; i < Y; i++)  //�ж���
	{
		if (chess[0][i] == ' ')  //������һ���ո񣬲������ڴ˴��������ӣ�����
			continue;
		else if (chess[0][i] == chess[1][i])
		{
			if (chess[0][i] == chess[2][i])
			{
				winner = chess[0][i];  //ȷ��ʤ������
				flag = 1;
				break;
			}
		}
	}
	if (!flag)
	{
		for (i = 0; i < Y; i++)  //�ж���
		{
			if (chess[i][0] == ' ')  //������һ���ո񣬲������ڴ˴��������ӣ�����
				continue;
			else if (chess[i][0] == chess[i][1])
			{
				if (chess[i][0] == chess[i][2])
				{
					winner = chess[i][0];  //ȷ��ʤ������
					flag = 1;
					break;
				}
			}
		}
	}
	if (!flag)  //�ж϶Խ���
	{
		if (chess[1][1] == ' ')  //�е�λ��Ϊ�ո񣬲������жԽ����������ӣ�����
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
	else if (n == 9)  //ƽ��
		return 3;
	else if (flag == 0)  //δ��ʤ��
		return 0;
	else
	{
		printf("\nJudgeError\n");
		return -1;
	}
}

void human(char chess[X][Y])  //˫��ģʽ
{
	char player[][6] = { "���1","���2" };
	printf("���1Ϊ����\n");
	char zi0 = chesstype(player[0]);  //ȷ��˫������
	char zi1 = chesstype(player[1]);
	while (zi0 == zi1)
	{
		printf("\n����ʹ����ͬ������\n\n");
		zi1 = chesstype(player[1]);
	}
	int flag = 1, result = 0, n = 0;
	system("cls");
	while (1)
	{
		char* p;
		char z;
		p = (flag == 1) ? player[0] : player[1];  //���ֵ����
		z = (flag == 1) ? zi0 : zi1;  //���ֵ����ʹ�õ�����
		round(player[0], player[1], zi0, zi1, chess, p, z, 0);  //�������
		flag = -flag;
		n++;
		result = judge(chess, zi0, zi1, n);  //�ж�ʤ��
		if (result != 0)
			break;
	}
	outcome(result, chess, player[0], player[1], zi0, zi1);  //���ʤ�����
}

void machine(char chess[X][Y], int dif)  //�˻�ģʽ
{
	int n = 0, flag = 0, result = 0;
	int* f = &flag;
	printf("ѡ�����ֵ�һ��:\n1.����  2.���\n\n");
	choose(f, 1, 2);  //����ѡ��
	system("cls");
	char player[][5] = { "����","���" };
	printf("%sΪ����\n", player[flag - 1]);
	char zi0 = chesstype(player[0]);  //ȷ��˫������
	char zi1 = chesstype(player[1]);
	while (zi0 == zi1)
	{
		printf("\n����ʹ����ͬ������\n\n");
		zi1 = chesstype(player[1]);
	}
	system("cls");
	if (flag == 2)  //�������ʱ��flag��Ϊ-1
		flag = -1;
	while (1)
	{
		char* p;  //���ֵ�һ��
		char z;  //���ֵ�һ��ʹ�õ�����
		p = (flag == 1) ? player[0] : player[1];
		z = (flag == 1) ? zi0 : zi1;
		if (flag == -1)
			round(player[0], player[1], zi0, zi1, chess, p, z, 0);  //��һغ�
		else
			round(player[0], player[1], zi0, zi1, chess, p, z, dif);  //���Իغ�
		n++;
		flag = -flag;
		result = judge(chess, zi0, zi1, n);  //�ж�ʤ��
		if (result != 0)
			break;
	}
	outcome(result, chess, player[0], player[1], zi0, zi1);  //���ʤ�����
}

void easy(char chess[X][Y], char z)  //easy�˻�
{
	int l[9] = { 0 };
	int i = 0, j = 0, ret = -1;
	char* position = &chess[0][0];
	for (i = 0; i < 9; i++)  //i��¼��λ��λ��
	{
		if ((*position == ' ') && (position != &chess[1][1]))  //���ֿ�λ������
		{
			l[j] = i;  //���µ�ǰ��λ��chess[0][0]λ�õľ���
			j++;  //jΪs����l[]�д������ЧԪ�ظ���������λ�ĸ���
		}
		position++;  //ָ��ָ����һ��λ��
		if (position > &chess[2][2])  //�����������鷶Χ
			break;
	}
	ret = 0 + rand() % j;  //����0��j-1�е�һ���������jΪ��λ����j-1��Ӧ���һ����λ��l[]�е��±�
	position = &chess[0][0];  //����ָ��
	position += l[ret];
	*position = z;
}

int amax(int a[], int n)  //�����������Ԫ�ص��±�
{
	int i, m = 0;
	for (i = 0; i < n; i++)
		if (a[i] > a[m])
			m = i;
	return m;
}

void hard(char chess[X][Y], char z, char z1)  //hard�˻�(����л���ȡʤʱ�������ң������л���ȡʤʱ������ȡʤ)
{
	int i = 0, j = 0, k = 0, flag = 0;
	char* p = &chess[0][0];
	for (i = 0; i < 9; i++)  //�۲����̿�λ����
	{
		if (*p == ' ')
			flag++;  //��¼���̿�λ��
		p++;
	}
	if ((flag == 8) || (flag == 9) || (flag == 1)) //�����һ��������ֱ�ӻ�ʤ�����
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
		for (i = 0; i < X; i++)  //���Խ���1����/��
		{
			if (chess[i][i] == z1)
				flag++;
			if (chess[i][i] == z)
				flag--;
		}
		if ((flag == 2) || (flag == -2))  //����ڴ�������������(��2)��������ڴ�������������(��-2)
		{
			for (j = 0; j < X; j++)
				if (chess[j][j] == ' ')
					chess[j][j] = z;
			return;
		}
		flag = 0;
		for (i = 0; i < X; i++)  //���Խ���2����\��
		{
			if (chess[i][X - i - 1] == z1)
				flag++;
			if (chess[i][X - i - 1] == z)
				flag--;
		}
		if ((flag == 2) || (flag == -2))  //����ڴ�������������(��2)��������ڴ�������������(��-2)
		{
			for (j = 0; j < X; j++)
				if (chess[j][X - j - 1] == ' ')
					chess[j][X - j - 1] = z;
			return;
		}
		flag = 0;
		int flag1 = 0;
		int x[X] = { 0 }; //����Ȩ�أ�Ԫ��Խ�󣬱�ʾԽӦ���ڸ�Ԫ���±��Ӧ��������
		for (i = 0; i < X; i++)  //���ÿһ��
		{
			flag = 0;
			for (j = 0; j < Y; j++)
			{
				if (chess[i][j] == z1)
					flag++;
				if (chess[i][j] == z)
					flag--;
			}
			if (flag >= 2)  //����ڴ�������������
			{
				x[i] = 1;
				flag1 = 1;
			}
			if (flag <= -2)  //�����ڴ�������������
			{
				x[i] = 2;
				flag1 = 1;
			}
		}
		if (flag1)
		{
			for (i = 0; i < Y; i++)  //��Ȩ������һ������
				if (chess[amax(x, X)][i] == ' ')
					chess[amax(x, X)][i] = z;
			return;
		}
		flag = 0, flag1 = 0;
		int y[Y] = { 0 };  //����Ȩ�أ�Ԫ��Խ�󣬱�ʾԽӦ���ڸ�Ԫ���±��Ӧ��������
		for (j = 0; j < Y; j++)  //���ÿһ��
		{
			flag = 0;
			for (i = 0; i < X; i++)
			{
				if (chess[i][j] == z1)
					flag++;
				if (chess[i][j] == z)
					flag--;
				
			}
			if (flag >= 2)  //����ڴ�������������
			{
				y[j] = 1;
				flag1 = 1;
			}
			if (flag <= -2)  //�����ڴ�������������
			{
				y[j] = 2;
				flag1 = 1;
			}
		}
		if (flag1)
		{
			for (i = 0; i < Y; i++)  //��Ȩ������һ������
				if (chess[i][amax(y, Y)] == ' ')
					chess[i][amax(y, Y)] = z;
			return;
		}
		easy(chess, z);
	}
}