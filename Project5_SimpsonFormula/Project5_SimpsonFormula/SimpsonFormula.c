//变步长辛普森公式
//Simpson Formula

#define _CRT_SECURE_NO_WARNINGS 1

#define MAXSIZE 1000

#include<stdio.h>
#include<math.h>

double f(double x)	 //被积函数 
{
	double F;
	if (x == 0) F = 1;
	else F = sin(x) / x;
	return F;
}

double T_n(double a, double b, double h)	//梯形公式 
{
	double Tn;
	Tn = h * (f(a) + f(b)) / 2;
	return Tn;
}

int main()
{
	double Tn, T2n, Sn, S2n, eps = 10e-6, h, a = 0, b = 1, s, temp;
	double x[MAXSIZE];
	int n, i, j, k;
	h = b - a;					printf("\nh=%.3lf", h);
	n = 1;
	x[0] = a;
	Tn = T_n(a, b, h);
	Sn = Tn;
	while (1)
	{
		printf("\nT[%d]=%lf\n", n, Tn);
		printf("S[%d]=%lf\n", n, Sn);
		s = 0; temp = 0;
		for (k = 0; k < n; k++)		//变步长的梯形公式 
		{
			temp = x[k] + h / 2;
			s += f(temp);
		}
		T2n = Tn / 2 + h * s / 2;			//变步长的梯形公式 
		S2n = (4 * T2n - Tn) / 3;		//辛普生公式 
		printf("T[%d]=%lf\n", 2 * n, T2n);
		printf("S[%d]=%lf\n", 2 * n, S2n);
		if (n >= MAXSIZE) break;	//数组容量达到上限 
		j = 0;
		printf("插入的点: ");
		for (i = n; i < 2 * n; i++) 		//将新插入的点储存在数组里 
		{
			x[i] = x[j] + h / 2;
			printf("x[%d]=%.3lf ", i, x[i]);
			j++;
		}
		printf("\n\n|S[%d]-S[%d]|=%lf ", 2 * n, n, fabs(S2n - Sn));
		if (fabs(S2n - Sn) <= eps)	//达到精度要求，退出循环 
		{
			printf("\n\n|S[%d]-Sn[%d]|=%lf达到精度要求\n", 2 * n, n, fabs(S2n - Sn));
			break;
		}
		else	//未达到精度要求 
		{
			h = h / 2;			printf("\n\nh=%.3lf", h);
			n = 2 * n;
			Tn = T2n;
			Sn = S2n;
		}
	}
	if (n >= MAXSIZE)
	{
		printf("\n错误\n");
		return -1;
	}
	else
	{
		printf("\n所积分的近似值为：%lf\n", S2n);
		return 0;
	}
}