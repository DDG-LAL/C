//���ɳڵ�����������Է�����
//Successive Over Relaxation Method

#define _CRT_SECURE_NO_WARNINGS 1

#define m 3

#include<stdio.h>
#include<math.h>

int main()
{
	double a[m][m], b[m];
	double x[m] = { 1, 1.5, 1.5 };  //��ʼ����������������
	double y[m];
	int i, j, k, n = 100;
	FILE* f;
	f = fopen("Matrix.txt", "r");  //��txt�ļ�������� 
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
			fscanf(f, "%lf", &a[i][j]);
		fscanf(f, "%lf", &b[i]);
	}
	fclose(f);
	double s, max, eps = 10e-6, w = 1.4;
	k = 1; //kΪ�������� 
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
		if (max < eps) break; //�ﵽ����Ҫ��epsʱֹͣ���� 
		printf("\nk=%d \n", k);
		for (i = 0; i < m; i++)
			printf("x[%d]=%.7lf\n", i, x[i]);
		k++;
	}
	if (k == n) //���������ﵽ100ʱ���� 
	{
		printf("����!\n");
		return 0;
	}
	printf("\n������Ľ�:\n");
	printf("��������k=%d \n", k); //������һ�ε����Ľ�� 
	for (i = 0; i < m; i++)
		printf("x[%d]=%.7lf\n", i, x[i]);
	return 1;
}
