#define _CRT_SECURE_NO_WARNINGS 1
//【用栈实现队列】
//

#include"StackFunc.h"
#include"StackImplementedQueueFunc.h"

int main()
{
	MyQueue* pq = myQueueCreate();
	myQueuePush(pq, 1);
	myQueuePush(pq, 5);
	myQueuePush(pq, 6);
	myQueuePush(pq, 7);
	myQueuePush(pq, 9);

	while (!myQueueEmpty(pq))
	{
		printf("%d ", myQueuePeek(pq));
		myQueuePop(pq);
	}
	printf("\n\n");
	myQueueFree(pq);
	pq = NULL;
	return 0;
}