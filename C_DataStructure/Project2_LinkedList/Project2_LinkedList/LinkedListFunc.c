#define _CRT_SECURE_NO_WARNINGS 1

#include"LinkedListFunc.h"

void LLprint(Node* phead)
{
	assert(phead);

	Node* cur = phead;
	while (cur)
	{
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}





void LLpushfront(Node** phead, LLdatatype x)
{
	assert(phead);

	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		perror("malloc");
		return;
	}
	tmp->data = x;
	tmp->next = *phead;
	*phead = tmp;
}