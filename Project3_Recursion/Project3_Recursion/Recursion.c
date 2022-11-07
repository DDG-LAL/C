//���������ݹ������

//�����ݹ�
//1�����������ȷ�ĵݹ������������Ϊ�ݹ���ڣ������������ʱ�򣬵ݹ鲻�ټ���
//2��ÿ�εݹ����֮�󶼱���Խ��Խ�ƽ��ݹ��������
//3���ݹ��β���̫���Ϊ�ڵݹ���õĹ��̵���ϵͳΪÿһ��ķ��ص㡢�ֲ������ȿ�����ջ���洢���ݹ���������������ջ���������
//4��ĳЩ�����ʹ�õݹ�ᵼ��Ч�ʽ���̫��
//5���Եݹ����ʽ��������һ��ȷǵݹ���ʽ������������һ�����ʵ�ֵ�Ч�ʱȵݹ�ʵ�ָ�
//6����һ������ǳ����ӣ������õ���ʵ�֣���ʱ�ݹ�ʵ�ֵļ���ԾͿ��Բ�����Ч�ʵ͵�ȱ�� 

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//����һ�����ͣ���˳���ӡ����ÿһλ
void print_int(int a)
{
	if (a > 9)  //�ݹ����
	{
		print_int(a / 10);  //�ƽ��ݹ��������
	}
	printf("%d ", a % 10);
}

//���ַ����ĳ���(strlen)��������ʹ����ʱ����
int strlength(char* a)
{
	if (*a != '\0')
		return 1 + strlength(a + 1);
	else
		return 0;
}

//�ݹ�ʵ�ֽ��ַ�������
void reverse_string1(char* a, int len)
{
	char* l = a;  //��ָ��
	char* r = a + len - 1;  //��ָ��
	char tmp = *l;
	*l = *r;
	*r = tmp;
	if (len > 2)  //����ǰ�ַ������ȴ���2������ָ�����ƣ���ָ�����ƣ��ٴν���
	{
		a++;
		len -= 2;
		reverse_string1(a, len);
	}
}

//���ݹ�ʵ�ֽ��ַ�������
void reverse_string2(char* arr)
{
	int len = strlen(arr);
	char* l = arr;
	char* r = arr + len - 1;
	while (r > l)
	{
		char tmp = *r;
		*r = *l;
		*l = tmp;
		l++;
		r--;
	}
}

//��һ�ֵݹ�ʵ�ֽ��ַ�������
void reverse_string3(char* arr)
{
	int len = strlen(arr);
	char tmp = *arr;
	*arr = *(arr + len - 1);
	*(arr + len - 1) = '\0';  //��ʱ�����һ���ַ���ֵΪ'\0'
	if (strlen(arr + 1) >= 2)  //ʣ��δ�����ִ��ڵ���2���ַ�
	{
		reverse_string3(arr + 1);
	}
	*(arr + len - 1) = tmp;
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
	while (n > 2) //���ڵ�n������ִ��(n-2)��
	{
		sum = a + b;
		a = b;
		b = sum;
		n--;
	}
	return sum;
}

//��ŵ������
//��ӡ�ƶ�����
void move(char x, char y)
{
	static int count = 0;  
	//static���ξֲ�������ʹ���ɾ�̬����
	//��̬����count�洢�ھ�̬������move�������ý���ʱcount�����Զ����٣�ֱ�������������ʱ����
	//������static���Σ��ֲ�����count�����洢��ջ������move�������ý���ʱcount���Զ�����
	printf("%c -> %c   ", x, y);
	count++;
	if (count % 5 == 0)
		printf("\n\n");
}
//��ӡn�㺺ŵ����Ҫ�Ĳ���
void Hanoi(int n, char a, char b, char c)  //��n��������b��a�ƶ���c
{
	if (n > 1)
	{
		Hanoi(n - 1, a, c, b);   //��n-1��������c��a�ƶ���b
		move(a, c);  //��a��ʣ�µ�һ�����ƶ���c
		Hanoi(n - 1, b, a, c);   //��n-1��������a��b�ƶ���c
	}
	else
	{
		move(a, c);  //��n==1����a�е�1����ֱ���ƶ���c
	}
}

//��̨������
//ÿ�ο�����1����2��̨�ף�������n��̨���ж���������
int jump(int n)
{
	if (n > 2)
		return jump(n - 1) + jump(n - 2);
	//else if (n == 2)
	//	return 2;
	//else  //(n == 1)
	//	return 1;
	else
		return n;
}

int main()
{
	char arr[11] = { "0" };
	printf("����һ���ַ���(10�ַ�����):");
	scanf("%s", arr);
	printf("\n��ӡ�ַ�������:%d", strlength(arr));

	reverse_string1(arr, strlen(arr));
	printf("\n��ӡ�����ַ���:%s", arr);
	reverse_string2(arr);
	printf("\n��ӡ�ٴ����õ��ַ���:%s", arr);
	reverse_string3(arr);
	printf("\n��ӡ���ٴ����õ��ַ���:%s", arr);

	int a = 0, i = 0;
	printf("\n\n����һ��int���͵���:");
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

	printf("\n\n��ӡ%d�㺺ŵ��������Ҫ�Ĳ���:\n", a);
	char A = 'a', B = 'b', C = 'c';
	Hanoi(a, A, B, C);

	printf("\n\n����%d��̨����%d������", a, jump(a));

	printf("\n");
	return 0;
}