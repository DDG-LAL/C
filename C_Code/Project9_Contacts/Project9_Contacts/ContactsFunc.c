#define _CRT_SECURE_NO_WARNINGS 1

#include "ContactsFunc.h"

int choose(int l, int r)  //选项选择
{
	int input = 0;
	while(1)
	{
		printf("输入选择:(范围:%d至%d)\n", l, r);
		fflush(stdin);
		scanf("%d", &input);
		if ((input >= l) && (input <= r))
			return input;
		else
			printf("\n输入错误!\n");
	}
	return input;
}

void InitContacts(Con* p)  //初始化通讯录
{
	assert(p);
	p->sz = 0;
	memset(p->peo, 0, sizeof(p->peo));
}

void AddContact(Con* p)  //添加联系人
{
	assert(p);
	if (p->sz >= CONTACT_MAX)
	{
		printf("\n通讯录已满，无法添加\n");
		return;
	}
	printf("输入姓名:");
	fflush(stdin);
	getchar();
	scanf("%c", p->peo[p->sz].name);
	printf("输入手机号:");
	printf("输入性别:");
	printf("输入年龄:");
	printf("输入地址:");
}