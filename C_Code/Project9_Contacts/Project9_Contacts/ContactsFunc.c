#define _CRT_SECURE_NO_WARNINGS 1

#include "ContactsFunc.h"

int choose(int l, int r)  //ѡ��ѡ��
{
	int input = 0;
	while(1)
	{
		printf("����ѡ��:(��Χ:%d��%d)\n", l, r);
		fflush(stdin);
		scanf("%d", &input);
		if ((input >= l) && (input <= r))
			return input;
		else
			printf("\n�������!\n");
	}
	return input;
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
	if (p->sz >= CONTACT_MAX)
	{
		printf("\nͨѶ¼�������޷����\n");
		return;
	}
	printf("��������:");
	fflush(stdin);
	getchar();
	scanf("%c", p->peo[p->sz].name);
	printf("�����ֻ���:");
	printf("�����Ա�:");
	printf("��������:");
	printf("�����ַ:");
}