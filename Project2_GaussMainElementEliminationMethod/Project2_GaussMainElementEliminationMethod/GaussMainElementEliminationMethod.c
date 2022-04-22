//高斯列主元法求解线性方程组

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
	printf("输入方程组阶数:"); 
	scanf("%ld", &n);  //%ld对应long类型
	printf("输入增广矩阵:\n");
	input(a, n);  //数组名就是地址，属于传址调用
	for (k = 0; k <= n - 2; k++)  //k遍历系数矩阵中的每一列
	{
		max = a[k][k];  //max存放列主元
		maxi = k;  //maxi用于存放列主元的下标
		for (i = k + 1; i <= n - 1; i++)  //k确定后，i遍历某一列中的每一行
		{
			if (fabs(a[i][k]) > fabs(max))  //选取列主元 
			{
				max = a[i][k];
				maxi = i;
			}
		}
		if (max == 0) 
			break;  //主元不能为0 
		if (maxi != k)  //交换行 
			for (j = k; j <= n; j++)
			{
				temp = a[k][j];
				a[k][j] = a[maxi][j];
				a[maxi][j] = temp;
			}
		for (i = k + 1; i <= n - 1; i++)  //行运算，使系数矩阵变成上三角矩阵 
		{
			a[i][k] /= -a[k][k];
			for (j = k + 1; j <= n; j++) 
				a[i][j] += a[i][k] * a[k][j];
		}
	}
	if (max == 0)  //主元不能为0 
		printf("\n错误\n");
	else
	{
		for (k = n - 1; k >= 0; k--)  //回代 
		{
			s = 0;
			for (j = k + 1; j <= n - 1; j++)
			{
				s += a[k][j] * x[j];
			}
			x[k] = (a[k][n] - s) / a[k][k];
		}
		printf("\n方程组的解:\n");
		output(x, n);
	}
	return 0;
}