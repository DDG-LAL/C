#define _CRT_SECURE_NO_WARNINGS 1

//����
//add del search modify sort print exit

#include "ContactsFunc.h"

void menu()
{
	printf("******************************\n");
	printf("            ͨѶ¼            \n\n");
	printf(" 1.add     2.del     3.search \n");
	printf(" 4.modify  5.sort    6.print  \n");
	printf(" 0.exit                       \n");
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
			break;
		case SEARCH:
			break;
		case MODIFY:
			break;
		case SORT:
			break;
		case PRINT:
			break;
		case EXIT:
			printf("\n�˳�\n");
			break;
		default:
			printf("\nerr\n");
			break;
		}
	} while (choice);
}

int main()
{
	RunContacts();
	return 0;
}