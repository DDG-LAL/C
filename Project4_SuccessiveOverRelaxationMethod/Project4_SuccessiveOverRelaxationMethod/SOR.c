//���ɳڵ�����������Է�����
//Successive Over Relaxation Method

#define _CRT_SECURE_NO_WARNINGS 1

#define m 3 //�������

#include<stdio.h>
#include<math.h>

int main()
{
	double a[m][m], b[m];
	double x[m] = { 1, 1.5, 1.5 };  //��ʼ���������������ã�x[m]��ž���Ľ�
	double y[m]; //y[m]����м���x[m]���м����������жϼ���������
	int i, j, k;

	//��txt�ļ��������
	FILE* f;  
	f = fopen("Matrix.txt", "r");  
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
			fscanf(f, "%lf", &a[i][j]);  //a[m][m]���ϵ������
		fscanf(f, "%lf", &b[i]);  //b[m]���������������һ��
	}
	fclose(f);

	int n = 200;  //nΪ����������
	double sum, max;  //����м���
	const double eps = 10e-6, w = 1.4;  //epsΪ����Ҫ��wΪ�ɳ�����
	k = 1; //kΪ�������� 
	do
	{
		max = 0;
		for (i = 0; i < m; i++)  //i���������ÿһ��
		{
			sum = 0;
			for (j = 0; j < m; j++)  //iȷ��ĳһ�к�j���������ÿһ��
			{
				sum += a[i][j] * x[j];  //���ɳڵ�����ʽ
			}
			y[i] = (b[i] - sum) / a[i][i];  //���ɳڵ�����ʽ
			y[i] = x[i] + w * y[i];  //���ɳڵ�����ʽ
			//������������µ�x[i]��ʱ�����y[i]��

			if (max < fabs(x[i] - y[i]))  //�������ϴ������x[i]�Ĳ�ֵ
			{
				max = fabs(x[i] - y[i]);  //ȡ����x�����ϴν����ֵ�е����ֵmax��Ϊ��ǰ����
			}
			x[i] = y[i];  //�����������x[i]����
		}

		if (max < eps) break;  //�ﵽ����Ҫ��epsʱֹͣ���� 
		printf("\n��%d�ε���:\n", k);  //���ÿ�ε����Ľ��
		for (i = 0; i < m; i++)
		{
			printf("x[%d]=%.7lf\n", i, x[i]);
		}
		k++;
	} while (k < n);

	if (k == n)  //���������ﵽ200ʱ���� 
	{
		printf("\n\nerror!\n\n");
		return -1;
	}
	printf("\n��������k=%d \n", k);  //������һ�ε����Ľ�� 
	printf("������Ľ�:\n");
	for (i = 0; i < m; i++)
	{
		printf("x[%d]=%.7lf\n", i, x[i]);
	}
	return 0;
}
