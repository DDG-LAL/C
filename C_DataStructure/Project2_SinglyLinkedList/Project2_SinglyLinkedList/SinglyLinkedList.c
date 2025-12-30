#define _CRT_SECURE_NO_WARNINGS 1

#include"SinglyLinkedListFunc.h"

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

	LLinsertBefore(&ps, LLsearch(ps, 3), 11);
	LLprint(ps);

	LLerase(&ps, LLsearch(ps, 4));
	LLerase(&ps, LLsearch(ps, 4));
	LLprint(ps);
	LLerase(&ps, LLsearch(ps, 3));
	LLprint(ps);

	LLinsertBefore(&ps, LLsearch(ps, 2), 121);
	LLinsertBefore(&ps, NULL, 131);
	LLprint(ps);
	LLerase(&ps, ps);
	LLerase(&ps, LLsearch(ps, 131));
	LLprint(ps);

	LLinsertAfter(ps->next->next->next, 99);
	LLprint(ps);
	LLeraseAfter(ps);
	LLeraseAfter(ps);
	LLeraseAfter(ps->next->next);
	LLprint(ps);

	//LLdestroy2(&ps);
	LLdestroy(ps);
	ps = NULL;

	return 0;
}
