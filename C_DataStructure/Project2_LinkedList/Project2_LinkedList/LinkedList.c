#define _CRT_SECURE_NO_WARNINGS 1

#include"LinkedListFunc.h"

void testpush(Node** ps)
{
	LLpushfront(ps, 1);
	LLpushfront(ps, 2);

	LLpushback(ps, 3);
	LLpushback(ps, 4);

	LLprint(*ps);
}


int main()
{
	Node* ps = NULL;
	/*ps->data = 0;
	ps->next = NULL;*/

	testpush(&ps);

	
	LLpopback(&ps);
	LLprint(ps);
	LLpopback(&ps);
	LLprint(ps);
	LLpopback(&ps);
	LLprint(ps);
	LLpopback(&ps);
	LLprint(ps);

	testpush(&ps);

	LLpopfront(&ps);
	LLprint(ps);
	LLpopfront(&ps);
	LLprint(ps);
	LLpopfront(&ps);
	LLprint(ps);
	LLpopfront(&ps);
	LLprint(ps);

	testpush(&ps);
	testpush(&ps);


	return 0;
}