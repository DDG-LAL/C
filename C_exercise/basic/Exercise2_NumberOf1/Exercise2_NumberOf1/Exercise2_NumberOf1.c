#define _CRT_SECURE_NO_WARNINGS 1
//【求1的数量】
//在32位环境下，求一个数在内存中的二进制序列中1的个数

#include<stdio.h>

//效率最低的方法，循环次数固定为32次
int Number1(int a)
{
	int sum = 0;
	for (int i = 0; i < 32; i++)
	{
		sum += a & 1;  //跟1进行按位与，若最低位为1则得1，若最低位为0则得0
		a = a >> 1;  //右移
	}
	return sum;
}

//效率高一点的方法，循环次数取决于二进制序列中最高位1的位置
int Number2(unsigned int a)  //使用unsigned int来接收参数是为了使用取模运算
{							 //若使用int，则当负数取模的时候会得到-1或0，不可能得到1
	int sum = 0;
	while (a)
	{
		if (a % 2 == 1)  //对于无符号数，模2所得的数即为二进制形式的最低位
			++sum;  
		a = a / 2;  //除以2，相当于右移
	}
	return sum;
}

//效率更高的方法，循环次数等于1的个数
int Number3(int a)  
{
	int sum = 0;
	while (a)
	{
		a = a & (a - 1);  //每运算一次，a的二进制序列中最右边的1就会被去掉
		++sum;			  //分两种情况：a的二进制序列最右边为1或0，这两种情况下进行a = a & (a - 1)都会将最右边的1去掉
	}
	return sum;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d %d %d", Number1(a), Number2(a), Number3(a));
	return 0;
}