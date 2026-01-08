#define _CRT_SECURE_NO_WARNINGS 1
//【实现循环队列】
//循环队列是一种线性数据结构，也被称为“环形缓冲器”
//循环队列的操作表现基于先进先出(FIFO)原则，且队尾连接在队首之后，形成一个循环
//
//循环队列的优势是，队列已经用过的空间可以再次被利用
//在一个普通队列里，一旦队列满了，即使在队列前面仍有空间，也不能插入下一个元素
//但是在循环队列中，队头的这些空间可以用于存储新的元素
//
//循环队列的实现应该支持如下操作：
//MyCircularQueue(k) : 构造器，设置队列长度为k
//Front : 获取队头元素，若队列为空则返回-1
//Rear : 获取队尾元素，若队列为空则返回-1
//enQueue(value) : 插入一个元素，成功插入则返回true
//deQueue() : 删除一个元素，成功删除则返回true
//isEmpty() : 检查循环队列是否为空
//isFull() : 检查循环队列是否已满

#include"CircularQueueFunc.h"

int main()
{
	MyCircularQueue* pq = myCircularQueueCreate(4);
	printf("%s ", myCircularQueueEnQueue(pq, 1) ? "true" : "false");
	printf("%s ", myCircularQueueEnQueue(pq, 2) ? "true" : "false");
	printf("%s ", myCircularQueueEnQueue(pq, 3) ? "true" : "false");
	printf("%s ", myCircularQueueEnQueue(pq, 4) ? "true" : "false");
	printf("%s ", myCircularQueueEnQueue(pq, 5) ? "true" : "false");
	printf("\n\n");

	while (!myCircularQueueIsEmpty(pq))
	{
		printf("%d %d\n", myCircularQueueFront(pq), myCircularQueueRear(pq));
		printf("%s\n\n", myCircularQueueDeQueue(pq) ? "true" : "false");
	}
	printf("%s\n\n", myCircularQueueDeQueue(pq) ? "true" : "false");
	myCircularQueueFree(pq);
	pq = NULL;
	return 0;
}