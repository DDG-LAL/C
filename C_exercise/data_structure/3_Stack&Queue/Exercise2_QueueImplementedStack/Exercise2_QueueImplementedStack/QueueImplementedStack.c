#define _CRT_SECURE_NO_WARNINGS 1
//【用队列实现栈】
//仅使用两个队列实现一个后入先出(LIFO)的栈，并支持普通栈的全部四种操作(push、pop、top、empty)
//实现MyStack
//void push(int x) 将元素x压入栈顶。
//int pop() 移除并返回栈顶元素
//int top() 返回栈顶元素
//boolean empty() 如果栈是空的，返回true，否则返回false
//注意：
//只能使用队列的标准操作：push to back、peek / pop from front、size、is empty

#include"QueueImplementedStackFunc.h"
#include"QueueFunc.h"

int main()
{
	MyStack* ps = myStackCreate();
	myStackPush(ps, 1);
	myStackPush(ps, 2);
	myStackPush(ps, 3);
	myStackPush(ps, 4);
	myStackPush(ps, 5);
	myStackPush(ps, 6);
	while (!myStackEmpty(ps))
	{
		printf("%d ", myStackTop(ps));
		myStackPop(ps);
	}
	printf("\n\n");
	myStackFree(ps);
	ps = NULL;
	return 0;
}