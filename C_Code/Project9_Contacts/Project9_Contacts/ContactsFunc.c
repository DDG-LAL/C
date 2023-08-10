#define _CRT_SECURE_NO_WARNINGS 1

#include "ContactsFunc.h"

int choose(int l, int r)  //ѡ��ѡ��
{
	int input = 0;
	while(1)
	{
		printf("����ѡ��:(��Χ:%d��%d)\n", l, r);
		rewind(stdin);
		scanf("%d", &input);
		if ((input >= l) && (input <= r))
			return input;
		else
			printf("\n�������!\n");
	}
}

int check(const Con* p, int flag)  //���ͨѶ¼״̬
{
	assert(p);
	if (0 == p->sz && 0 == flag)
	{
		printf("ͨѶ¼Ϊ��\n\n");
		system("pause");
		return 1;
	}
	else if (CONTACT_MAX == p->sz && 1 == flag)
	{
		printf("ͨѶ¼����\n\n");
		system("pause");
		return 1;
	}
	else
		return 0;
}

void reset_num(Con* p)  //�������
{
	assert(p);
	for (int i = 0; i < p->sz; ++i)
		p->peo[i].num = i + 1;
}

void InitContacts(Con* p)  //��ʼ��ͨѶ¼
{
	assert(p);
	p->sz = 0;
	memset(p->peo, 0, sizeof(p->peo));
}

void AddContact(Con* p)  //�����ϵ��
{
	assert(p);
	p->peo[p->sz].num = p->sz + 1;
	if (check(p, 1))  //���ͨѶ¼�Ƿ�����
		return;
	printf("��������:");
	rewind(stdin);
	scanf("%s", p->peo[p->sz].name);
	printf("�����ֻ���:");
	rewind(stdin);
	scanf("%s", p->peo[p->sz].mobile);
	printf("�����Ա�:");
	rewind(stdin);
	scanf("%s", p->peo[p->sz].gen);
	printf("��������:");
	rewind(stdin);
	scanf("%d", &(p->peo[p->sz].age));
	printf("�����ַ:");
	rewind(stdin);
	scanf("%s", p->peo[p->sz].addr);
	++p->sz;
}

void PrintContact(const Con* p, int l, int r)  //��ӡ����ͨѶ¼
{
	assert(p);
	if (check(p, 0))  //���ͨѶ¼�Ƿ�Ϊ��
		return;
	printf  //��ӡ��ͷ
	(
		"%-6s%-15s%-15s%-10s%-10s%-10s\n",
		"���", "����", "�ֻ���", "�Ա�", "����", "��ַ"
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

int FindContact(const Con* p)  //������ϵ�ˣ��ɹ��򷵻��±꣬���򷵻�-1
{
	assert(p);
	if (check(p, 0))  //���ͨѶ¼�Ƿ�Ϊ��
		return -1;
	int num = -1;
	char data[NAME_MAX] = { 0 };
	printf("������ʽ:1.���������� 2.���ֻ�������\n");
	int type = choose(1, 2);
	if (1 == type)
		printf("\n��������:");
	else if (2 == type)
		printf("\n�����ֻ���:");
	rewind(stdin);
	scanf("%s", data);

	if (1 == type)  //����������
	{
		for (int i = 0; i < p->sz; ++i)
		{
			if (0 == strcmp(data, p->peo[i].name))
				return i;
		}
	}
	else if (2 == type)  //���ֻ��Ų���
	{
		for (int i = 0; i < p->sz; ++i)
		{
			if (0 == strcmp(data, p->peo[i].mobile))
				return i;
		}
	}
	else
		return -2;
	printf("\nû���ҵ�����ϵ��\n\n");
	system("pause");
	return -1;
}

void SearchContact(const Con* p)  //������ϵ�ˣ��ɹ����ӡ
{
	assert(p);
	if (check(p, 0))  //���ͨѶ¼�Ƿ�Ϊ��
		return;
	int num = FindContact(p);
	printf("\n");
	if (num >= 0)
		PrintContact(p, num, num);
	return;
}

void DelContact(Con* p)  //ɾ��ָ����ϵ��
{
	assert(p);
	if (check(p, 0))  //���ͨѶ¼�Ƿ�Ϊ��
		return;
	int num = FindContact(p);
	if (num == -1)
		return;
	for (int i = num; i < p->sz; ++i)
		p->peo[i] = p->peo[i + 1];
	--p->sz;
	reset_num(p);
	printf("\nɾ���ɹ�\n\n");
	system("pause");
}
