#define _CRT_SECURE_NO_WARNINGS 1
//【2的整数幂次方】
//输入一个整数，判断该数是否为2的整数幂次方
//若是则返回True，否则返回False

#include<stdio.h>
#include<stdbool.h>

//普通的方法
bool judge1(int a)
{
	if (a == 1)  //1是2的0次幂
		return true;
	while (a)
	{
		if (0 == a % 2)  //模2如果不得0说明是奇数或0，排除
		{
			a = a / 2;  //模2得0则除以2
			if (a == 1)  //一直除以2如果最终商为1，说明原本的数是2的整数幂次方
				break;
		}
		else
			return false;
	}
	return true;
}

//高效的方法
bool judge2(int a)
{
	bool ret = false;
	if ((a & (a - 1)) == 0)  //2的整数次幂的二进制序列中只有1个1
		ret = true;
	return ret;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d %d\n", judge1(a), judge2(a));
	return 0;
}