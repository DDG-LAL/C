//���������ݹ������

//�����ݹ�
//1�����������ȷ�ĵݹ������������Ϊ�ݹ���ڣ������������ʱ�򣬵ݹ鲻�ټ���
//2��ÿ�εݹ����֮�󶼻�Խ��Խ�ƽ��ݹ��������
//3���ݹ��β���̫���Ϊ�ڵݹ���õĹ��̵���ϵͳΪÿһ��ķ��ص㡢�ֲ������ȿ�����ջ���洢���ݹ���������������ջ���������
//4��ĳЩ�����ʹ�õݹ�ᵼ��Ч�ʽ���̫��
//5���Եݹ����ʽ��������һ��ȷǵݹ���ʽ������������һ�����ʵ�ֵ�Ч�ʱȵݹ�ʵ�ָ�
//6����һ������ǳ����ӣ������õ���ʵ�֣���ʱ�ݹ�ʵ�ֵļ���ԾͿ��Բ�����Ч�ʵ͵�ȱ�� 

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//����һ�����ͣ���˳���ӡ����ÿһλ
void print_int(int a)
{
	if (a > 9)  //�ݹ����
	{
		print_int(a / 10);  //�ƽ��ݹ��������
	}
	printf("%d ", a % 10);
}

//���ַ����ĳ���(strlen)
int strlength(char* a)
{
	if (*a != '\0')
		return 1 + strlength(a + 1);
	else
		return 0;
}

//��n�Ľ׳�
int Factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * Factorial(n - 1);
}

//�ݹ����n��쳲������� ����> n�ϴ�ʱ����д����ظ����㣬����Ч�ʵ�
int fib1(int n)
{
	if (n > 2)
		return fib1(n - 1) + fib1(n - 2);
	else 
		return 1;
}

//���ݹ����n��쳲�������
int fib2(int n)
{
	int sum = 1, a = 1, b = 1;
	/*int i = 0;
	if (n > 2)
	{
		for (i = 0; i < n - 2; i++)
		{
			sum = a + b;
			a = b;
			b = sum;
		}
	}*/
	while (n > 2)
	{
		sum = a + b;
		a = b;
		b = sum;
		n--;
	}
	return sum;
}

//��ŵ������
void Hanoi(int n)
{
	
}


int main()
{
	int a = 0, i = 0;
	printf("����һ��int���͵���:");
	scanf("%d", &a);
	printf("\n��ӡÿһλ����:");
	print_int(a);
	printf("\n��ӡ%d�Ľ׳�:%d", a, Factorial(a));
	printf("\n��ӡǰ%d��쳲�������:\n", a);
	for (i = 0; i < a; i++)
		printf("%d ", fib1(i + 1));
	printf("\n��ӡǰ%d��쳲�������:\n", a);
	for (i = 0; i < a; i++)
		printf("%d ", fib2(i + 1));

	char arr[20] = { "0" };
	printf("\n\n����һ���ַ���:");
	scanf("%s", arr);
	printf("\n��ӡ�ַ�������:%d", strlength(arr));



	printf("\n");
	return 0;
}