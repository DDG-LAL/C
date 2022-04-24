//超松弛迭代法求解线性方程组
//Successive Over Relaxation Method

#define _CRT_SECURE_NO_WARNINGS 1

#define m 3

#include<stdio.h>
#include<math.h>

int main()
{
	double a[m][m], b[m];
	double x[m] = { 1, 1.5, 1.5 };  //初始向量可以随意设置
	double y[m];
	int i, j, k, n = 100;
	FILE* f;
	f = fopen("Matrix.txt", "r");  //从txt文件输入矩阵 
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
			fscanf(f, "%lf", &a[i][j]);
		fscanf(f, "%lf", &b[i]);
	}
	fclose(f);
	double s, max, eps = 10e-6, w = 1.4;
	k = 1; //k为迭代次数 
	while (k < n)
	{
		max = 0;
		for (i = 0; i < m; i++)
		{
			s = 0;
			for (j = 0; j < m; j++) s += a[i][j] * x[j];
			y[i] = (b[i] - s) / a[i][i];
			y[i] = x[i] + w * y[i];

			if (max < fabs(x[i] - y[i])) max = fabs(x[i] - y[i]);
			x[i] = y[i];
		}
		if (max < eps) break; //达到精度要求eps时停止迭代 
		printf("\nk=%d \n", k);
		for (i = 0; i < m; i++)
			printf("x[%d]=%.7lf\n", i, x[i]);
		k++;
	}
	if (k == n) //迭代次数达到100时报错 
	{
		printf("错误!\n");
		return 0;
	}
	printf("\n方程组的解:\n");
	printf("迭代次数k=%d \n", k); //输出最后一次迭代的结果 
	for (i = 0; i < m; i++)
		printf("x[%d]=%.7lf\n", i, x[i]);
	return 1;
}
