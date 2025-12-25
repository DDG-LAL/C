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
	SLpushback(&s, 5);
	SLpushback(&s, 7);
	SLpushback(&s, 9);
	SLprint(&s);
	SLdestroy(&s);
	return 0;
}