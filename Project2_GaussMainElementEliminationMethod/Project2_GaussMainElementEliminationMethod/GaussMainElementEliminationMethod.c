//��˹����Ԫ��������Է�����

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>
#define MAXSIZE 100


void input(double a[MAXSIZE][MAXSIZE + 1], long n)  //����n�����Է�������������
{
	long i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n + 1; j++)
			scanf("%lf", &a[i][j]);
}
void output(double x[MAXSIZE], long n)  //���������Ľ�
{
	long k;
	for (k = 1; k <= n; k++)
		printf("x[%ld]=%lf ", k, x[k - 1]);
	printf("\n");
}
int main()
{
	double a[MAXSIZE][MAXSIZE + 1], x[MAXSIZE], max, temp;
	long n, i, j, k, maxi;
	printf("���뷽�������:"); 
	scanf("%ld", &n);  //%ld��Ӧlong����
	printf("�����������:\n");
	input(a, n);  //���������ǵ�ַ�����ڴ�ַ����
	for (k = 0; k < n - 1; k++)  //k����ϵ�������г������һ��֮���ÿһ��
	{
		max = a[k][k];  //max�������Ԫ
		maxi = k;  //maxi�������Ԫ���±�
		for (i = k + 1; i < n; i++)  //kȷ��ĳһ�к�i���������дӵ�k+2�п�ʼ���µ�ÿһ��
		{
			if (fabs(a[i][k]) > fabs(max))  //ѡȡ����Ԫ 
			{
				max = a[i][k];
				maxi = i;
			}
		}
		if (max == 0) 
			break;  //��Ԫ����Ϊ0 
		if (maxi != k)  //������Ԫ���ڵ�k+1�У�������������н����У�����Ԫ������k+1��
			for (i = k; i < n + 1; i++)  //i�����������ӵ�k+1�п�ʼ���ҵ�ÿһ��
			{
				temp = a[k][i];
				a[k][i] = a[maxi][i];
				a[maxi][i] = temp;
			}
		//�����㣬ʹϵ�������𲽱�������Ǿ���
		for (i = k + 1; i < n; i++)  //i������������дӵ�k+2�п�ʼ���µ�ÿһ��
		{
			temp = a[i][k] / -a[k][k];  //����������ϵ��temp
			for (j = k + 1; j < n + 1; j++)  //iȷ��ĳһ�к�j������������дӵ�k+2�п�ʼ���ҵ�ÿһ��
				a[i][j] += temp * a[k][j];  //��temp���Ե�k+1�У��ӵ���ǰȷ�����У�ʹ�ø��е�һ��Ԫ�ر�Ϊ0
		}
	}
	if (max == 0)  //��Ԫ����Ϊ0 
		printf("\n����\n");
	else
	{
		for (k = n - 1; k >= 0; k--)  //�ش���⣬k�������������һ�б�������һ�� 
		{
			temp = 0;
			for (j = k + 1; j < n; j++)  //kȷ��ĳһ�к�j�����Ӹ��е�k+2�б��������һ��
			{
				temp += a[k][j] * x[j];  //����һ������(��������е���һ��)�õ��Ĳ��ֽ�ش�����ǰ����
			}
			x[k] = (a[k][n] - temp) / a[k][k];  //����ó���ʹδ֪����ϵ����Ϊ1
		}
		printf("\n������Ľ�:\n");
		output(x, n);
	}
	return 0;
}