#define _CRT_SECURE_NO_WARNINGS 1

#include"LinkedListFunc.h"

int main()
{
	Node* ps = NULL;
	/*ps->data = 0;
	ps->next = NULL;*/
	LLpushfront(&ps, 1);
	LLpushfront(&ps, 2);
	LLpushfront(&ps, 3);
	LLpushfront(&ps, 4);

	LLprint(ps);
	return 0;
}