//…®¿◊”Œœ∑

#define _CRT_SECURE_NO_WARNINGS 1

#include"GameFunc.h"

void menu()
{
	system("cls");
	printf("********************************************\n");
	printf("*                                          *\n");
	printf("*                 …®¿◊”Œœ∑                 *\n");
	printf("*                                          *\n");
	printf("*                  1.Play                  *\n");
	printf("*                  0.Exit                  *\n");
	printf("*                                          *\n");
	printf("********************************************\n\n");
}

void game()
{
	int mine[X][Y] = { 0 };
	char board[X][Y];
	int situation = 0;
	initial(mine, board);
	while (situation == 0)
	{
		display(board);
		printf("\n");
		test(mine);
		situation = play(mine, board);
		display(board);
		system("pause");
		system("cls");
	}
	display(board);
	switch (situation)
	{
	case -1:
		printf("\n\nƒ„ ‰¡À\n");
		break;
	case -2:
		printf("\n\nerr\n");
		break;
	case 1:
		printf("\n\nƒ„”Æ¡À\n");
		break;
	default:
		printf("\n\nerr\n");
		break;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int choice = 0;
	do
	{
		int* c = &choice;
		menu();
		choose(c, 1, 0);
		switch (choice)
		{
		case 1:
			system("cls");
			game();
			break;
		case 0:
			printf("\nÕÀ≥ˆ”Œœ∑\n");
			break;
		default:
			printf("\nChoiceErr\n");
			system("pause");
			break;
		}
	} while (choice);
	return 0;
}