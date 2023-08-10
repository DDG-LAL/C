#define _CRT_SECURE_NO_WARNINGS 1

#include "ContactsFunc.h"

int choose(int l, int r)  //选项选择
{
	int input = 0;
	while(1)
	{
		printf("输入选择:(范围:%d至%d)\n", l, r);
		rewind(stdin);
		scanf("%d", &input);
		if ((input >= l) && (input <= r))
			return input;
		else
			printf("\n输入错误!\n");
	}
}

int check(const Con* p, int flag)  //检查通讯录状态
{
	assert(p);
	if (0 == p->sz && 0 == flag)
	{
		printf("通讯录为空\n\n");
		system("pause");
		return 1;
	}
	else if (CONTACT_MAX == p->sz && 1 == flag)
	{
		printf("通讯录已满\n\n");
		system("pause");
		return 1;
	}
	else
		return 0;
}

void reset_num(Con* p)  //重置序号
{
	assert(p);
	for (int i = 0; i < p->sz; ++i)
		p->peo[i].num = i + 1;
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
	p->peo[p->sz].num = p->sz + 1;
	if (check(p, 1))  //检查通讯录是否已满
		return;
	printf("输入姓名:");
	rewind(stdin);
	scanf("%s", p->peo[p->sz].name);
	printf("输入手机号:");
	rewind(stdin);
	scanf("%s", p->peo[p->sz].mobile);
	printf("输入性别:");
	rewind(stdin);
	scanf("%s", p->peo[p->sz].gen);
	printf("输入年龄:");
	rewind(stdin);
	scanf("%d", &(p->peo[p->sz].age));
	printf("输入地址:");
	rewind(stdin);
	scanf("%s", p->peo[p->sz].addr);
	++p->sz;
}

void PrintContact(const Con* p, int l, int r)  //打印部分通讯录
{
	assert(p);
	if (check(p, 0))  //检查通讯录是否为空
		return;
	printf  //打印表头
	(
		"%-6s%-15s%-15s%-10s%-10s%-10s\n",
		"序号", "姓名", "手机号", "性别", "年龄", "地址"
	);
	for (int i = l; i <= r; ++i)
	{
		printf
		(
			"%-6d%-15s%-15s%-10s%-10d%-10s\n",
			p->peo[i].num,
			p->peo[i].name,
			p->peo[i].mobile,
			p->peo[i].gen,
			p->peo[i].age,
			p->peo[i].addr
		);
	}
	printf("\n");
	system("pause");
}

int FindContact(const Con* p, int type, char* mes)  //查找联系人，成功则返回下标，否则返回-1
{
	assert(p);
	if (check(p, 0))  //检查通讯录是否为空
		return -1;
	if (1 == type)  //以姓名查找
	{
		for (int i = 0; i < p->sz; ++i)
		{
			if (0 == strcmp(mes, p->peo[i].name))
				return i;
		}
		return -1;
	}
	else if (2 == type)  //以手机号查找
	{
		for (int i = 0; i < p->sz; ++i)
		{
			if (0 == strcmp(mes, p->peo[i].mobile))
				return i;
		}
		return -1;
	}
	else
		return -2;
}

void SearchContact(const Con* p)  //搜索联系人，成功则打印
{
	assert(p);
	if (check(p, 0))  //检查通讯录是否为空
		return;
	printf("搜索方式:1.以姓名搜索 2.以手机号搜索\n");
	int type = choose(1, 2), num;
	char data[NAME_MAX];
	if (1 == type)
		printf("\n输入姓名:");
	else if (2 == type)
		printf("\n输入手机号:");
	rewind(stdin);
	scanf("%s", data);
	num = FindContact(p, type, data);
	if (num >= 0)
		PrintContact(p, num, num);
	else
	{
		printf("\n没有找到该联系人\n\n");
		system("pause");
	}
}