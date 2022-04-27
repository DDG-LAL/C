//�䲽������ɭ��ʽ
//Simpson Formula

#define _CRT_SECURE_NO_WARNINGS 1

#define MAXSIZE 1000

#include<stdio.h>
#include<math.h>

double f(double x)	 //�������� 
{
	double F;
	if (x == 0) F = 1;
	else F = sin(x) / x;
	return F;
}

double T_n(double a, double b, double h)	//���ι�ʽ 
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
		for (k = 0; k < n; k++)		//�䲽�������ι�ʽ 
		{
			temp = x[k] + h / 2;
			s += f(temp);
		}
		T2n = Tn / 2 + h * s / 2;			//�䲽�������ι�ʽ 
		S2n = (4 * T2n - Tn) / 3;		//��������ʽ 
		printf("T[%d]=%lf\n", 2 * n, T2n);
		printf("S[%d]=%lf\n", 2 * n, S2n);
		if (n >= MAXSIZE) break;	//���������ﵽ���� 
		j = 0;
		printf("����ĵ�: ");
		for (i = n; i < 2 * n; i++) 		//���²���ĵ㴢���������� 
		{
			x[i] = x[j] + h / 2;
			printf("x[%d]=%.3lf ", i, x[i]);
			j++;
		}
		printf("\n\n|S[%d]-S[%d]|=%lf ", 2 * n, n, fabs(S2n - Sn));
		if (fabs(S2n - Sn) <= eps)	//�ﵽ����Ҫ���˳�ѭ�� 
		{
			printf("\n\n|S[%d]-Sn[%d]|=%lf�ﵽ����Ҫ��\n", 2 * n, n, fabs(S2n - Sn));
			break;
		}
		else	//δ�ﵽ����Ҫ�� 
		{
			h = h / 2;			printf("\n\nh=%.3lf", h);
			n = 2 * n;
			Tn = T2n;
			Sn = S2n;
		}
	}
	if (n >= MAXSIZE)
	{
		printf("\n����\n");
		return -1;
	}
	else
	{
		printf("\n�����ֵĽ���ֵΪ��%lf\n", S2n);
		return 0;
	}
}