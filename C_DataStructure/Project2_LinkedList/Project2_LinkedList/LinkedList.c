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
	LLpushback(ps, 4);
	LLpushback(ps, 5);
	LLpushback(ps, 6);

	LLprint(ps);
	return 0;
}