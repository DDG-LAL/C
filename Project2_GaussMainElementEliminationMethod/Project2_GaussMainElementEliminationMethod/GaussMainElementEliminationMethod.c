//��˹����Ԫ��������Է�����

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>
#define MAXSIZE 100


void input(double a[MAXSIZE][MAXSIZE + 1], long n)  
{
	long i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n + 1; j++)
			scanf("%lf", &a[i][j]);
}
void output(double x[MAXSIZE], long n)
{
	long k;
	for (k = 1; k <= n; k++)
		printf("x[%d]=%lf ", k, x[k - 1]);
}
int main()
{
	double a[MAXSIZE][MAXSIZE + 1], x[MAXSIZE], s, max, temp;
	long n, i, j, k, maxi;
	printf("���뷽�������:"); 
	scanf("%ld", &n);  //%ld��Ӧlong����
	printf("�����������:\n");
	input(a, n);  //���������ǵ�ַ�����ڴ�ַ����
	for (k = 0; k <= n - 2; k++)  //k����ϵ�������е�ÿһ��
	{
		max = a[k][k];  //max�������Ԫ
		maxi = k;  //maxi���ڴ������Ԫ���±�
		for (i = k + 1; i <= n - 1; i++)  //kȷ����i����ĳһ���е�ÿһ��
		{
			if (fabs(a[i][k]) > fabs(max))  //ѡȡ����Ԫ 
			{
				max = a[i][k];
				maxi = i;
			}
		}
		if (max == 0) 
			break;  //��Ԫ����Ϊ0 
		if (maxi != k)  //������ 
			for (j = k; j <= n; j++)
			{
				temp = a[k][j];
				a[k][j] = a[maxi][j];
				a[maxi][j] = temp;
			}
		for (i = k + 1; i <= n - 1; i++)  //�����㣬ʹϵ�������������Ǿ��� 
		{
			a[i][k] /= -a[k][k];
			for (j = k + 1; j <= n; j++) 
				a[i][j] += a[i][k] * a[k][j];
		}
	}
	if (max == 0)  //��Ԫ����Ϊ0 
		printf("\n����\n");
	else
	{
		for (k = n - 1; k >= 0; k--)  //�ش� 
		{
			s = 0;
			for (j = k + 1; j <= n - 1; j++)
			{
				s += a[k][j] * x[j];
			}
			x[k] = (a[k][n] - s) / a[k][k];
		}
		printf("\n������Ľ�:\n");
		output(x, n);
	}
	return 0;
}