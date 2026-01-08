#define _CRT_SECURE_NO_WARNINGS 1
//【用栈实现队列】
//仅使用两个栈实现一个先入先出(FIFO)的队列，并支持普通队列的全部操作(push、pop、peek、empty)
//实现MyQueue
//void push(int x) 将元素x插入队列的末尾
//int pop() 移除并返回队头元素
//int peek() 返回队头元素
//boolean empty() 若队列为空，返回true，否则返回false
//注意：
//只能使用栈的标准操作：push to top、peek / pop from top、size、is empty

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