//高斯列主元法求解线性方程组

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>
#define MAXSIZE 100


void input(double a[MAXSIZE][MAXSIZE + 1], long n)  //输入n阶线性方程组的增广矩阵
{
	long i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n + 1; j++)
			scanf("%lf", &a[i][j]);
}
void output(double x[MAXSIZE], long n)  //输出方程组的解
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
	printf("输入方程组阶数:"); 
	scanf("%ld", &n);  //%ld对应long类型
	printf("输入增广矩阵:\n");
	input(a, n);  //数组名就是地址，属于传址调用
	for (k = 0; k < n - 1; k++)  //k遍历系数矩阵中除了最后一列之外的每一列
	{
		max = a[k][k];  //max存放列主元
		maxi = k;  //maxi存放列主元的下标
		for (i = k + 1; i < n; i++)  //k确定某一列后，i遍历该列中从第k+2行开始往下的每一行
		{
			if (fabs(a[i][k]) > fabs(max))  //选取列主元 
			{
				max = a[i][k];
				maxi = i;
			}
		}
		if (max == 0) 
			break;  //主元不能为0 
		if (maxi != k)  //若列主元不在第k+1行，则对增广矩阵进行交换行，将主元换到第k+1行
			for (i = k; i < n + 1; i++)  //i遍历增广矩阵从第k+1列开始往右的每一列
			{
				temp = a[k][i];
				a[k][i] = a[maxi][i];
				a[maxi][i] = temp;
			}
		//行运算，使系数矩阵逐步变成上三角矩阵
		for (i = k + 1; i < n; i++)  //i遍历增广矩阵中从第k+2行开始往下的每一行
		{
			temp = a[i][k] / -a[k][k];  //获得行运算的系数temp
			for (j = k + 1; j < n + 1; j++)  //i确定某一行后，j遍历增广矩阵中从第k+2列开始往右的每一列
				a[i][j] += temp * a[k][j];  //将temp乘以第k+1行，加到当前确定的行，使得该行第一个元素变为0
		}
	}
	if (max == 0)  //主元不能为0 
		printf("\n错误\n");
	else
	{
		for (k = n - 1; k >= 0; k--)  //回代求解，k从增广矩阵的最后一行遍历到第一行 
		{
			temp = 0;
			for (j = k + 1; j < n; j++)  //k确定某一行后，j遍历从该行第k+2列遍历到最后一列
			{
				temp += a[k][j] * x[j];  //将上一次运算(增广矩阵中的下一行)得到的部分解回代到当前的行
			}
			x[k] = (a[k][n] - temp) / a[k][k];  //移项并用除法使未知数的系数变为1
		}
		printf("\n方程组的解:\n");
		output(x, n);
	}
	return 0;
}