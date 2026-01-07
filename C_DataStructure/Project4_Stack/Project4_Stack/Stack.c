#define _CRT_SECURE_NO_WARNINGS 1

#include"StackFunc.h"

int main()
{
	ST s;
	ST* ps = &s;
	STinit(ps);
	STpush(ps, 9);
	STpush(ps, 6);
	STpush(ps, 3);
	STpush(ps, 1);
	printf("%d\n\n", STsize(ps));
	while (!STempty(ps))
	{
		printf("%d ", STtop(ps));
		STpop(ps);
	}
	printf("\n");
	STdestroy(ps);
	return 0;
}