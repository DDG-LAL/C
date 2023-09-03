//ͨѶ¼

#define _CRT_SECURE_NO_WARNINGS 1

#include "ContactsFunc1.h"

void menu()
{
	system("cls");
	printf("******************************\n");
	printf("            ͨѶ¼            \n\n");
	printf(" 1.Add     2.Del     3.Search \n");
	printf(" 4.Modify  5.Sort    6.Print  \n");
	printf(" 7.Clear   0.Exit             \n");
	printf("******************************\n");
}

void init_test  //��ʼ������
(
	Info* p,
	int num,
	char name[NAME_MAX],
	char mobile[MOBILE_MAX],
	char gen[GEN_MAX],
	int age,
	char addr[ADDR_MAX]
)
{
	p->num = num;
	strcpy(p->name, name);
	p->age = age;
	strcpy(p->gen, gen);
	strcpy(p->mobile, mobile);
	strcpy(p->addr, addr);
}

void test(Con* p)  //������
{
	p->sz = 10;
	init_test(&(p->peo[0]), 1, "Qdbsdf", "456", "s", 3, "qwe");
	init_test(&(p->peo[1]), 2, "bsdf", "6", "dass", 83, "qwde");
	init_test(&(p->peo[2]), 3, "498*f", "456", "s", 13, "qwe");
	init_test(&(p->peo[3]), 4, "QSDw", "456", "s", 93, "qwe");
	init_test(&(p->peo[4]), 5, "Asdf", "456", "s", 1, "qwe");
	init_test(&(p->peo[5]), 6, "*/sdf", "456", "s", 50, "qwe");
	init_test(&(p->peo[6]), 7, "Bscdf", "456", "s", 35, "qwe");
	init_test(&(p->peo[7]), 8, "���", "456", "s", 5, "qwe");
	init_test(&(p->peo[8]), 9, "������", "456", "s", 65, "qwe");
	init_test(&(p->peo[9]), 10, "495", "456", "s", 685, "qwe");
}

void RunContacts()  //����ͨѶ¼
{
	int choice = 0;
	Con con;
	InitContacts(&con);

	//test(&con);  //������

	do
	{
		menu();
		choice = choose(0, 7);
		system("cls");
		switch (choice)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case PRINT:
			PrintContact(&con, 0, con.sz - 1);
			break;
		case CLEAR:
			ClearContact(&con);
			break;
		case EXIT:
			printf("\n�˳�\n");
			break;
		default:
			printf("\nerr_run\n\n");
			system("pause");
			break;
		}
	} while (choice);
}

int main()
{
	RunContacts();
	return 0;
}