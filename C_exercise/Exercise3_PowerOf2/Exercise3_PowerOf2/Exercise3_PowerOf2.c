#define _CRT_SECURE_NO_WARNINGS 1
//��2�������ݴη���
//����һ���������жϸ����Ƿ�Ϊ2�������ݴη�
//�����򷵻�True�����򷵻�False

#include<stdio.h>
#include<stdbool.h>

//��ͨ�ķ���
bool judge1(int a)
{
	if (a == 1)  //1��2��0����
		return true;
	while (a)
	{
		if (0 == a % 2)  //ģ2�������0˵����������0���ų�
		{
			a = a / 2;  //ģ2��0�����2
			if (a == 1)  //һֱ����2���������Ϊ1��˵��ԭ��������2�������ݴη�
				break;
		}
		else
			return false;
	}
	return true;
}

//��Ч�ķ���
bool judge2(int a)
{
	bool ret = false;
	if ((a & (a - 1)) == 0)  //2���������ݵĶ�����������ֻ��1��1
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