#define _CRT_SECURE_NO_WARNINGS 1

#include"QueueFunc.h"



int main()
{
	Queue q;
	Queue* pq = &q;
	Qinit(pq);
	Qpush(pq, 1);
	Qpush(pq, 5);
	Qpush(pq, 6);
	Qpush(pq, 7);
	Qpush(pq, 9);
	printf("%d\n%d %d\n\n", Qsize(pq), Qfront(pq), Qback(pq));
	Qpop(pq);
	printf("%d\n%d %d\n\n", Qsize(pq), Qfront(pq), Qback(pq));
	Qdestroy(pq);
	pq = NULL;
	return 0;
}