#define _CRT_SECURE_NO_WARNINGS 1

#include"DoublyLinkedListFunc.h"

void test(DLLnode* s)
{
	DLLpushback(s, 1);
	DLLpushback(s, 2);
	DLLpushback(s, 3);
	DLLpushfront(s, 9);
	DLLpushfront(s, 8);
	DLLpushfront(s, 7);
	DLLprint(s);
}

int main()
{
	DLLnode* s = DLLcreate();

	test(s);
	DLLpopback(s);
	DLLprint(s);
	DLLpopfront(s);
	DLLprint(s);
	DLLpopback(s);
	DLLpopback(s);
	DLLpopfront(s);
	DLLpopfront(s);
	DLLprint(s);

	test(s);
	DLLnode* pos = DLLsearch(s, 1);
	if (pos)
		DLLinsert(pos, 0);
	DLLprint(s);

	DLLdestroy1(s);
	s = NULL;
	printf("\n");

	DLLnode* tmp = DLLcreate();
	test(tmp);
	DLLdestroy2(tmp);
	tmp = NULL;

	return 0;
}