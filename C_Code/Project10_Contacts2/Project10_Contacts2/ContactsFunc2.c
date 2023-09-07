#define _CRT_SECURE_NO_WARNINGS 1

#include "ContactsFunc2.h"

int choose(int l, int r)  //ѡ��ѡ��
{
	int input = 0;
	while (1)
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

//��̬
//int check(const Con* p, int flag)  //���ͨѶ¼״̬
//{
//	assert(p);
//	if (0 == p->sz && 0 == flag)
//	{
//		printf("ͨѶ¼Ϊ��\n\n");
//		system("pause");
//		return 1;
//	}
//	else if (CONTACT_MAX == p->sz && 1 == flag)
//	{
//		printf("ͨѶ¼����\n\n");
//		system("pause");
//		return 1;
//	}
//	else
//		return 0;
//}

//��̬
int is_empty(const Con* p)  //���ͨѶ¼�Ƿ�Ϊ��
{
	assert(p);
	if (0 == p->sz)
	{
		printf("\nͨѶ¼Ϊ��\n\n");
		system("pause");
		return 1;
	}
	return 0;
}

//��̬
void is_full(Con* p)  //���ͨѶ¼�Ƿ�������������������
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

			//printf("\n�����ݣ���ǰ����Ϊ%d\n\n", p->cap);  //������
		}
	}
}

void reset_num(Con* p)  //�������
{
	assert(p);
	for (int i = 0; i < p->sz; ++i)
		p->peo[i].num = i + 1;
}

//��̬
//void InitContacts(Con* p)  //��ʼ��ͨѶ¼
//{
//	assert(p);
//	p->sz = 0;
//	memset(p->peo, 0, sizeof(p->peo));
//}

//��̬
void InitContacts(Con* p)  //��ʼ��ͨѶ¼
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

void AddContact(Con* p)  //������ϵ��
{
	assert(p);

	//��̬
	//if (check(p, 1))  //���ͨѶ¼�Ƿ�����
	//	return;

	//��̬
	is_full(p);

	p->peo[p->sz].num = p->sz + 1;
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
	printf("\n���ӳɹ�\n\n");
	system("pause");
}

void PrintContacts(const Con* p, int l, int r)  //��ӡ����ͨѶ¼
{
	assert(p);

	//��̬
	//if (check(p, 0))  //���ͨѶ¼�Ƿ�Ϊ��
	//	return;

	//��̬
	if (is_empty(p))
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

	//��̬
	//if (check(p, 0))  //���ͨѶ¼�Ƿ�Ϊ��
	//	return -1;

	//��̬
	if (is_empty(p))
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

	//��̬
	//if (check(p, 0))  //���ͨѶ¼�Ƿ�Ϊ��
	//	return;

	//��̬
	if (is_empty(p))
		return;

	int num = FindContact(p);
	printf("\n");
	if (num >= 0)
		PrintContacts(p, num, num);
}

void DelContact(Con* p)  //ɾ��ָ����ϵ��
{
	assert(p);

	//��̬
	//if (check(p, 0))  //���ͨѶ¼�Ƿ�Ϊ��
	//	return;

	//��̬
	if (is_empty(p))
		return;

	int num = FindContact(p);
	if (num < 0)
		return;
	else
	{
		printf("\n��Ҫɾ������ϵ������:\n\n");
		PrintContacts(p, num, num);
	}
	for (int i = num; i < p->sz; ++i)
		p->peo[i] = p->peo[i + 1];
	--p->sz;
	reset_num(p);
	printf("\nɾ���ɹ�\n\n");
	system("pause");
}

void ModifyContact(Con* p)  //�޸�ָ����ϵ��
{
	assert(p);

	//��̬
	//if (check(p, 0))  //���ͨѶ¼�Ƿ�Ϊ��
	//	return;

	//��̬
	if (is_empty(p))
		return;

	int tmp = p->sz;
	int num = FindContact(p);
	if (num >= 0)
	{
		printf("\n��Ҫ�޸ĵ���ϵ������:\n\n");
		PrintContacts(p, num, num);
		p->sz = num;
		printf("\n");
		AddContact(p);
		printf("\n�޸ĳɹ�\n\n");
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

int namecmp(const char* str1, const char* str2)  //�Ƚ������ַ�������str1>str2�򷵻ش���0������
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

	//��̬
	//if (check(p, 0))  //���ͨѶ¼�Ƿ�Ϊ��
	//	return;

	//��̬
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

	//��̬
	//if (check(p, 0))  //���ͨѶ¼�Ƿ�Ϊ��
	//	return;

	//��̬
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


void SortContacts(Con* p)  //������ϵ��
{
	assert(p);

	//��̬
	//if (check(p, 0))  //���ͨѶ¼�Ƿ�Ϊ��
	//	return;

	//��̬
	if (is_empty(p))
		return;

	printf("����ʽ:1.����������ĸ���� 2.����������\n");
	if (1 == choose(1, 2))
		SortByName(p);
	else
		SortByAge(p);
	reset_num(p);
	printf("\n����ɹ�\n\n");
	system("pause");
}

void ClearContacts(Con* p)  //���ͨѶ¼
{
	assert(p);

	//��̬
	//if (check(p, 0))  //���ͨѶ¼�Ƿ�Ϊ��
	//	return;

	//��̬
	if (is_empty(p))
		return;

	printf("�������ͨѶ¼���Ƿ�ȷ����\n1.ȷ��  2.ȡ��\n");
	if (1 == choose(1, 2))
	{
		//��̬
		free(p->peo);

		InitContacts(p);
		printf("\n������\n\n");
		system("pause");
	}
	else
	{
		printf("\n��ղ�����ȡ��\n\n");
		system("pause");
	}
}

//��̬
void DeleteContacts(Con* p)  //ɾ��ͨѶ¼
{
	free(p->peo);
	p->peo = NULL;

	//printf("\n��̬�ڴ����ͷ�\n");  //������
}