//几个函数递归的例子

//函数递归
//1、必须存在明确的递归结束条件，称为递归出口，当条件满足的时候，递归不再继续
//2、每次递归调用之后都必须越来越逼近递归结束条件
//3、递归层次不能太深，因为在递归调用的过程当中系统为每一层的返回点、局部变量等开辟了栈来存储，递归次数过多容易造成栈溢出等问题
//4、某些情况下使用递归会导致效率降低太多
//5、以递归的形式解释问题一般比非递归形式更清晰，但是一般迭代实现的效率比递归实现高
//6、当一个问题非常复杂，难以用迭代实现，此时递归实现的简洁性就可以补偿其效率低的缺陷 

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//接收一个整型，按顺序打印它的每一位
void print_int(int a)
{
	if (a > 9)  //递归出口
	{
		print_int(a / 10);  //逼近递归结束条件
	}
	printf("%d ", a % 10);
}

//求字符串的长度(strlen)，不允许使用临时变量
int strlength(char* a)
{
	if (*a != '\0')
		return 1 + strlength(a + 1);
	else
		return 0;
}

//递归实现将字符串逆置
void reverse_string1(char* a, int len)
{
	char* l = a;  //左指针
	char* r = a + len - 1;  //右指针
	char tmp = *l;
	*l = *r;
	*r = tmp;
	if (len > 2)  //若当前字符串长度大于2，将左指针右移，右指针左移，再次交换
	{
		a++;
		len -= 2;
		reverse_string1(a, len);
	}
}

//不递归实现将字符串逆置
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

//另一种递归实现将字符串逆置
void reverse_string3(char* arr)
{
	int len = strlen(arr);
	char tmp = *arr;
	*arr = *(arr + len - 1);
	*(arr + len - 1) = '\0';  //暂时将最后一个字符赋值为'\0'
	if (strlen(arr + 1) >= 2)  //剩下未处理部分大于等于2个字符
	{
		reverse_string3(arr + 1);
	}
	*(arr + len - 1) = tmp;
}

//求n的阶乘
int Factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * Factorial(n - 1);
}

//递归求第n个斐波那契数 ——> n较大时会进行大量重复计算，导致效率低
int fib1(int n)
{
	if (n > 2)
		return fib1(n - 1) + fib1(n - 2);
	else 
		return 1;
}

//不递归求第n个斐波那契数
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
	while (n > 2) //对于第n个数，执行(n-2)次
	{
		sum = a + b;
		a = b;
		b = sum;
		n--;
	}
	return sum;
}

//汉诺塔问题
//打印移动步骤
void move(char x, char y)
{
	static int count = 0;  
	//static修饰局部变量，使其变成静态变量
	//静态变量count存储在静态区，当move函数调用结束时count不会自动销毁，直到整个程序结束时销毁
	//若不用static修饰，局部变量count本来存储在栈区，当move函数调用结束时count会自动销毁
	printf("%c -> %c   ", x, y);
	count++;
	if (count % 5 == 0)
		printf("\n\n");
}
//打印n层汉诺塔需要的步骤
void Hanoi(int n, char a, char b, char c)  //将n层塔借助b从a移动到c
{
	if (n > 1)
	{
		Hanoi(n - 1, a, c, b);   //将n-1层塔借助c从a移动到b
		move(a, c);  //将a中剩下的一层塔移动到c
		Hanoi(n - 1, b, a, c);   //将n-1层塔借助a从b移动到c
	}
	else
	{
		move(a, c);  //当n==1，将a中的1层塔直接移动到c
	}
}

//跳台阶问题
//每次可以跳1个或2个台阶，求跳上n个台阶有多少种跳法
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
	printf("输入一个字符串(10字符以内):");
	scanf("%s", arr);
	printf("\n打印字符串长度:%d", strlength(arr));

	reverse_string1(arr, strlen(arr));
	printf("\n打印逆置字符串:%s", arr);
	reverse_string2(arr);
	printf("\n打印再次逆置的字符串:%s", arr);
	reverse_string3(arr);
	printf("\n打印再再次逆置的字符串:%s", arr);

	int a = 0, i = 0;
	printf("\n\n输入一个int类型的数:");
	scanf("%d", &a);
	printf("\n打印每一位数字:");
	print_int(a);

	printf("\n打印%d的阶乘:%d", a, Factorial(a));

	printf("\n打印前%d个斐波那契数:\n", a);
	for (i = 0; i < a; i++)
		printf("%d ", fib1(i + 1));
	printf("\n打印前%d个斐波那契数:\n", a);
	for (i = 0; i < a; i++)
		printf("%d ", fib2(i + 1));

	printf("\n\n打印%d层汉诺塔问题需要的步骤:\n", a);
	char A = 'a', B = 'b', C = 'c';
	Hanoi(a, A, B, C);

	printf("\n\n跳上%d个台阶有%d种跳法", a, jump(a));

	printf("\n");
	return 0;
}