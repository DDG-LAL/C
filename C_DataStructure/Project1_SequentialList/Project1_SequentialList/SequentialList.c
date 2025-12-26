#define _CRT_SECURE_NO_WARNINGS 1

#include"SequentialListFunc.h"


int main()
{
	SL s;
	SLinit(&s);
	SLpushback(&s, 1);
	SLpushback(&s, 2);
	SLpushback(&s, 3);
	SLpushback(&s, 4);
	SLpushfront(&s, 5);
	SLpushfront(&s, 6);
	SLpushback(&s, 7);
	SLpushfront(&s, 8);
	SLpushfront(&s, 9);
	SLprint(&s);

	SLpopback(&s);
	SLpopback(&s);
	SLprint(&s); 

	SLpopfront(&s);
	SLpopfront(&s);
	SLprint(&s);

	SLinsert(&s, 2, 11);
	SLprint(&s);

	SLerase(&s, 3);
	SLprint(&s);
	SLerase(&s, 2);
	SLprint(&s);

	printf("%d %d\n", SLsearch(&s, 3), SLsearch(&s, 100)); //≤È’“

	SLmodify(&s, 1, 1);
	SLprint(&s);



	SLdestroy(&s);
	return 0;
}