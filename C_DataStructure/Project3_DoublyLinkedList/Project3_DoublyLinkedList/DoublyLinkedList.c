#define _CRT_SECURE_NO_WARNINGS 1

#include"DoublyLinkedListFunc.h"

int main()
{
	DLLnode* s = DLLcreate();
	DLLpushback(s, 1);
	DLLpushback(s, 2);
	DLLpushback(s, 3);
	DLLpushfront(s, 9);
	DLLpushfront(s, 8);
	DLLpushfront(s, 7);
	DLLprint(s);

	DLLpopback(s);
	DLLprint(s);
	DLLpopfront(s);
	DLLprint(s);

	DLLpopback(s);
	DLLpopback(s);
	DLLpopfront(s);
	DLLpopfront(s);
	DLLprint(s);


	return 0;
}