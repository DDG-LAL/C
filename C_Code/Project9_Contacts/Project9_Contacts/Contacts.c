//ͨѶ¼

#define _CRT_SECURE_NO_WARNINGS 1

#include "ContactsFunc.h"

void menu()
{
	system("cls");
	printf("******************************\n");
	printf("            ͨѶ¼            \n\n");
	printf(" 1.Add     2.Del     3.Search \n");
	printf(" 4.Modify  5.Sort    6.Print  \n");
	printf(" 0.Exit                       \n");
	printf("******************************\n");
}

void RunContacts()  //����ͨѶ¼
{
	int choice = 0;
	Con con;
	InitContacts(&con);
	do
	{
		menu();
		choice = choose(0, 6);
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

			break;
		case SORT:

			break;
		case PRINT:
			PrintContact(&con, 0, con.sz - 1);
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