#define _CRT_SECURE_NO_WARNINGS 1
//¡¾¡¿
//

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
	if (!headA || !headB)
		return NULL;
	struct ListNode* tailA = headA, * tailB = headB;
	while (tailB->next)
		tailB = tailB->next;
	tailB->next = headA;
	struct ListNode* fast = headB, * slow = headB;
	while (fast && fast->next)
	{
		if (fast == slow)
			return fast;
		fast = fast->next->next;
		slow = slow->next;
	}
	return NULL;
}

int main()
{
	struct ListNode* p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(p1);
	struct ListNode* p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(p2);
	struct ListNode* p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(p3);
	struct ListNode* p4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(p4);
	struct ListNode* p5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(p5);
	struct ListNode* p6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(p6);
	struct ListNode* p7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(p7);
	struct ListNode* p8 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(p8);
	struct ListNode* p9 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(p9);
	struct ListNode* p10 = (struct ListNode*)malloc(sizeof(struct ListNode));
	assert(p10);
	p1->val = 1;
	p2->val = 2;
	p3->val = 3;
	p4->val = 4;
	p5->val = 5;
	p6->val = 6;
	p7->val = 7;
	p8->val = 8;
	p9->val = 10;
	p10->val = 11;

	p1->next = p3;
	p3->next = p5;
	p5->next = p7;
	p7->next = p9;

	p2->next = p4;
	p4->next = p6;
	p6->next = p8;
	p8->next = p9;

	p9->next = p10;
	p10->next = NULL;

	struct ListNode* tmp;
	tmp = getIntersectionNode(p1, p2);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");
	return 0;
}