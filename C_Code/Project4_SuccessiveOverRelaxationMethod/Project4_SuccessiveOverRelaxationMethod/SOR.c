//超松弛迭代法求解线性方程组
//Successive Over Relaxation Method

#define _CRT_SECURE_NO_WARNINGS 1

#define m 3 //矩阵阶数

#include<stdio.h>
#include<math.h>

int main()
{
	double a[m][m], b[m];
	double x[m] = { 1, 1.5, 1.5 };  //初始向量可以随意设置，x[m]存放矩阵的解
	double y[m]; //y[m]存放中间结果x[m]的中间结果，用于判断计算结果精度
	int i, j, k;

	//从txt文件输入矩阵
	FILE* f;  
	f = fopen("Matrix.txt", "r");  
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
			fscanf(f, "%lf", &a[i][j]);  //a[m][m]存放系数矩阵
		fscanf(f, "%lf", &b[i]);  //b[m]存放增广矩阵的最右一列
	}
	fclose(f);

	int n = 200;  //n为最大迭代次数
	double sum, max;  //存放中间结果
	const double eps = 10e-6, w = 1.4;  //eps为精度要求，w为松弛因子
	k = 1; //k为迭代次数 
	do
	{
		max = 0;
		for (i = 0; i < m; i++)  //i遍历矩阵的每一行
		{
			sum = 0;
			for (j = 0; j < m; j++)  //i确定某一行后，j遍历矩阵的每一列
			{
				sum += a[i][j] * x[j];  //超松弛迭代公式
			}
			y[i] = (b[i] - sum) / a[i][i];  //超松弛迭代公式
			y[i] = x[i] + w * y[i];  //超松弛迭代公式
			//将本次算出的新的x[i]暂时存放在y[i]中

			if (max < fabs(x[i] - y[i]))  //本次与上次算出的x[i]的差值
			{
				max = fabs(x[i] - y[i]);  //取所有x中与上次结果差值中的最大值max作为当前精度
			}
			x[i] = y[i];  //将本次算出的x[i]更新
		}

		if (max < eps) break;  //达到精度要求eps时停止迭代 
		printf("\n第%d次迭代:\n", k);  //输出每次迭代的结果
		for (i = 0; i < m; i++)
		{
			printf("x[%d]=%.7lf\n", i, x[i]);
		}
		k++;
	} while (k < n);

	if (k == n)  //迭代次数达到200时报错 
	{
		printf("\n\nerror!\n\n");
		return -1;
	}
	printf("\n迭代次数k=%d \n", k);  //输出最后一次迭代的结果 
	printf("方程组的解:\n");
	for (i = 0; i < m; i++)
	{
		printf("x[%d]=%.7lf\n", i, x[i]);
	}
	return 0;
}
