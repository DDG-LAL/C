#define _CRT_SECURE_NO_WARNINGS 1

#include "ContactsFunc3.h"

int choose(int l, int r)  //选项选择
{
	int input = 0;
	while (1)
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

//静态
//int check(const Con* p, int flag)  //检查通讯录状态
//{
//	assert(p);
//	if (0 == p->sz && 0 == flag)
//	{
//		printf("通讯录为空\n\n");
//		system("pause");
//		return 1;
//	}
//	else if (CONTACT_MAX == p->sz && 1 == flag)
//	{
//		printf("通讯录已满\n\n");
//		system("pause");
//		return 1;
//	}
//	else
//		return 0;
//}

//动态
int is_empty(const Con* p)  //检查通讯录是否为空
{
	assert(p);
	if (0 == p->sz)
	{
		printf("\n通讯录为空\n\n");
		system("pause");
		return 1;
	}
	return 0;
}

//动态
void is_full(Con* p)  //检查通讯录是否已满，若已满则扩容
{
	assert(p);
	if (p->sz == p->cap)
	{
		Info* tmp = (Info*)realloc(p->peo, (p->cap + DEFAULT_ADD) * sizeof(Info));
		if (tmp == NULL)
		{
			perror("is_full::realloc");
			return;
		}
		else
		{
			p->peo = tmp;
			tmp = NULL;
			p->cap += DEFAULT_ADD;

			//printf("\n已扩容，当前容量为%d\n\n", p->cap);  //测试用
		}
	}
}

void reset_num(Con* p)  //重置序号
{
	assert(p);
	for (int i = 0; i < p->sz; ++i)
		p->peo[i].num = i + 1;
}

//静态
//void InitContacts(Con* p)  //初始化通讯录
//{
//	assert(p);
//	p->sz = 0;
//	memset(p->peo, 0, sizeof(p->peo));
//}

//动态
void InitContacts(Con* p)  //初始化通讯录
{
	assert(p);
	p->sz = 0;
	p->cap = DEFAULT_CAP;
	p->peo = (Info*)malloc(DEFAULT_CAP * sizeof(Info));
	if (p->peo == NULL)
	{
		perror("InitContacts::malloc");
		return;
	}
	memset(p->peo, 0, DEFAULT_CAP * sizeof(Info));
}

//通过文件实现数据存储
void InitDat(Con* p)  //从文件读取数据
{
	FILE* pf = fopen("ContactsData.dat", "rb");
	if (pf == NULL)
	{
		perror("InitDat::fopen");
		return;
	}
	Info tmp = { 0 };
	while (fread(&tmp, sizeof(Info), 1, pf))
	{
		is_full(p);
		p->peo[p->sz] = tmp;
		++p->sz;
	}
	fclose(pf);
	pf = NULL;
}

void AddContact(Con* p)  //添加联系人
{
	assert(p);

	//静态
	//if (check(p, 1))  //检查通讯录是否已满
	//	return;

	//动态
	is_full(p);

	p->peo[p->sz].num = p->sz + 1;
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
	printf("\n添加成功\n\n");
	system("pause");
}

void PrintContacts(const Con* p, int l, int r)  //打印部分通讯录
{
	assert(p);

	//静态
	//if (check(p, 0))  //检查通讯录是否为空
	//	return;

	//动态
	if (is_empty(p))
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

int FindContact(const Con* p)  //查找联系人，成功则返回下标，否则返回-1
{
	assert(p);

	//静态
	//if (check(p, 0))  //检查通讯录是否为空
	//	return -1;

	//动态
	if (is_empty(p))
		return -1;

	int num = -1;
	char data[NAME_MAX] = { 0 };
	printf("搜索方式:1.以姓名搜索 2.以手机号搜索\n");
	int type = choose(1, 2);
	if (1 == type)
		printf("\n输入姓名:");
	else if (2 == type)
		printf("\n输入手机号:");
	rewind(stdin);
	scanf("%s", data);

	if (1 == type)  //以姓名查找
	{
		for (int i = 0; i < p->sz; ++i)
		{
			if (0 == strcmp(data, p->peo[i].name))
				return i;
		}
	}
	else if (2 == type)  //以手机号查找
	{
		for (int i = 0; i < p->sz; ++i)
		{
			if (0 == strcmp(data, p->peo[i].mobile))
				return i;
		}
	}
	else
		return -2;
	printf("\n没有找到该联系人\n\n");
	system("pause");
	return -1;
}

void SearchContact(const Con* p)  //搜索联系人，成功则打印
{
	assert(p);

	//静态
	//if (check(p, 0))  //检查通讯录是否为空
	//	return;

	//动态
	if (is_empty(p))
		return;

	int num = FindContact(p);
	printf("\n");
	if (num >= 0)
		PrintContacts(p, num, num);
}

void DelContact(Con* p)  //删除指定联系人
{
	assert(p);

	//静态
	//if (check(p, 0))  //检查通讯录是否为空
	//	return;

	//动态
	if (is_empty(p))
		return;

	int num = FindContact(p);
	if (num < 0)
		return;
	else
	{
		printf("\n将要删除的联系人如下:\n\n");
		PrintContacts(p, num, num);
	}
	for (int i = num; i < p->sz; ++i)
		p->peo[i] = p->peo[i + 1];
	--p->sz;
	reset_num(p);
	printf("\n删除成功\n\n");
	system("pause");
}

void ModifyContact(Con* p)  //修改指定联系人
{
	assert(p);

	//静态
	//if (check(p, 0))  //检查通讯录是否为空
	//	return;

	//动态
	if (is_empty(p))
		return;

	int tmp = p->sz;
	int num = FindContact(p);
	if (num >= 0)
	{
		printf("\n将要修改的联系人如下:\n\n");
		PrintContacts(p, num, num);
		p->sz = num;
		printf("\n");
		AddContact(p);
		printf("\n修改成功\n\n");
		system("pause");
	}
	p->sz = tmp;
}

int is_letter(char a)
{
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return 1;
	else
		return 0;
}

int namecmp(const char* str1, const char* str2)  //比较两个字符串，若str1>str2则返回大于0的整数
{
	assert(str1 && str2);
	const char* a = str1;
	const char* b = str2;
	while (1)
	{
		if (*a == *b)
		{
			if (*a == '\0')
				return 0;
		}
		else if (*a >= 'A' && *a <= 'Z' && *b >= 'a' && *b <= 'z')
		{
			if (0 == (*a - 'A') - (*b - 'a'))
				return -1;
			else
				return (int)((*a - 'A') - (*b - 'a'));
		}
		else if (*a >= 'a' && *a <= 'z' && *b >= 'A' && *b <= 'Z')
		{
			if (0 == (*a - 'a') - (*b - 'A'))
				return 1;
			else
				return (int)((*a - 'a') - (*b - 'A'));
		}
		else if (is_letter(*a) && !is_letter(*b))
			return 0;
		else if (!is_letter(*a) && is_letter(*b))
			return 1;
		else
			return (int)(*a - *b);
		++a;
		++b;
	}
}

void SortByName(Con* p)
{
	assert(p);

	//静态
	//if (check(p, 0))  //检查通讯录是否为空
	//	return;

	//动态
	if (is_empty(p))
		return;

	for (int i = 0; i < p->sz; ++i)
	{
		for (int j = 0; j < p->sz - i - 1; ++j)
		{
			if (namecmp(p->peo[j].name, p->peo[j + 1].name) > 0)
			{
				Info tmp;
				tmp = p->peo[j];
				p->peo[j] = p->peo[j + 1];
				p->peo[j + 1] = tmp;
			}
		}
	}
}

void SortByAge(Con* p)
{
	assert(p);

	//静态
	//if (check(p, 0))  //检查通讯录是否为空
	//	return;

	//动态
	if (is_empty(p))
		return;

	for (int i = 0; i < p->sz; ++i)
	{
		for (int j = 0; j < p->sz - i - 1; ++j)
		{
			if (p->peo[j].age - p->peo[j + 1].age > 0)
			{
				Info tmp;
				tmp = p->peo[j];
				p->peo[j] = p->peo[j + 1];
				p->peo[j + 1] = tmp;
			}
		}
	}
}


void SortContacts(Con* p)  //排序联系人
{
	assert(p);

	//静态
	//if (check(p, 0))  //检查通讯录是否为空
	//	return;

	//动态
	if (is_empty(p))
		return;

	printf("排序方式:1.按姓名首字母排序 2.按年龄排序\n");
	if (1 == choose(1, 2))
		SortByName(p);
	else
		SortByAge(p);
	reset_num(p);
	printf("\n排序成功\n\n");
	system("pause");
}

void ClearContacts(Con* p)  //清空通讯录
{
	assert(p);

	//静态
	//if (check(p, 0))  //检查通讯录是否为空
	//	return;

	//动态
	if (is_empty(p))
		return;

	printf("即将清空通讯录，是否确定？\n1.确定  2.取消\n");
	if (1 == choose(1, 2))
	{
		//动态
		free(p->peo);

		InitContacts(p);
		printf("\n清空完成\n\n");
		system("pause");
	}
	else
	{
		printf("\n清空操作已取消\n\n");
		system("pause");
	}
}

//动态
void DeleteContacts(Con* p)  //删除通讯录
{
	free(p->peo);
	p->peo = NULL;

	//printf("\n动态内存已释放\n");  //测试用
}

//通过文件实现数据存储
void SaveDat(Con* p)  //将数据保存到文件
{
	assert(p);
	FILE* pf = fopen("ContactsData.dat", "wb");
	if (pf == NULL)
	{
		perror("SaveDat::fopen");
		return;
	}
	for (int i = 0; i < p->sz; ++i)
		fwrite(&(p->peo[i]), sizeof(Info), 1, pf);
	fclose(pf);
	pf = NULL;
}