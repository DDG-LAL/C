#define _CRT_SECURE_NO_WARNINGS 1

#include"SinglyLinkedListFunc.h"

void testpush(SLLnode** ps)
{
	SLLpushfront(ps, 1);
	SLLpushfront(ps, 2);

	SLLpushback(ps, 3);
	SLLpushback(ps, 4);

	SLLprint(*ps);
}

int main()
{
	SLLnode* ps = NULL;
	/*ps->data = 0;
	ps->next = NULL;*/

	testpush(&ps);

	SLLpopback(&ps);
	SLLprint(ps);
	SLLpopback(&ps);
	SLLprint(ps);
	SLLpopback(&ps);
	SLLprint(ps);
	SLLpopback(&ps);
	SLLprint(ps);

	testpush(&ps);

	SLLpopfront(&ps);
	SLLprint(ps);
	SLLpopfront(&ps);
	SLLprint(ps);
	SLLpopfront(&ps);
	SLLprint(ps);
	SLLpopfront(&ps);
	SLLprint(ps);

	testpush(&ps);
	testpush(&ps);

	SLLinsertBefore(&ps, SLLsearch(ps, 3), 11);
	SLLprint(ps);

	SLLerase(&ps, SLLsearch(ps, 4));
	SLLerase(&ps, SLLsearch(ps, 4));
	SLLprint(ps);
	SLLerase(&ps, SLLsearch(ps, 3));
	SLLprint(ps);

	SLLinsertBefore(&ps, SLLsearch(ps, 2), 121);
	SLLinsertBefore(&ps, NULL, 131);
	SLLprint(ps);
	SLLerase(&ps, ps);
	SLLerase(&ps, SLLsearch(ps, 131));
	SLLprint(ps);

	SLLinsertAfter(ps->next->next->next, 99);
	SLLprint(ps);
	SLLeraseAfter(ps);
	SLLeraseAfter(ps);
	SLLeraseAfter(ps->next->next);
	SLLprint(ps);

	SLLdestroy(ps);
	ps = NULL;

	SLLnode* tmp = NULL;
	testpush(&tmp);
	SLLdestroy2(&tmp);


	return 0;
}
