#define _CRT_SECURE_NO_WARNINGS 1
//【相交链表】
//给出两个不带环单链表的头节点headA和headB，要求找出并返回两个单链表相交的起始节点
//若两个链表不存在相交节点，则返回NULL
//函数返回结果后，要求链表必须保持其原始结构

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

struct ListNode* getIntersectionNode1(struct ListNode* headA, struct ListNode* headB)
{
	if (!headA || !headB)
		return NULL;
	struct ListNode* tailA = headA, * tailB = headB;
	while (tailB->next)
		tailB = tailB->next;
	while (tailA->next)
		tailA = tailA->next;
	if (tailA != tailB)
		return NULL;
	tailB->next = headA;
	struct ListNode* fast = headB, * slow = headB;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			break;
	}
	fast = headB;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	tailB->next = NULL;
	return fast;
}

struct ListNode* getIntersectionNode2(struct ListNode* headA, struct ListNode* headB)
{
	if (!headA || !headB)
		return NULL;
	struct ListNode* tailA = headA, * tailB = headB;
	int countA = 1, countB = 1, dist = 0;
	while (tailA->next)
	{
		tailA = tailA->next;
		countA++;
	}
	while (tailB->next)
	{
		tailB = tailB->next;
		countB++;
	}
	if (tailA != tailB)
		return NULL;
	if (countB > countA)
	{
		struct ListNode* tmp = headA;
		headA = headB;
		headB = tmp;
	}
	dist = abs(countA - countB);
	while (dist--)
		headA = headA->next;
	while (headA != headB)
	{
		assert(headA && headB); //避免C28182警告
		headA = headA->next;
		headB = headB->next;
	}
	return headA;
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
	tmp = getIntersectionNode1(p1, p2);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");
	tmp = getIntersectionNode1(p10, p2);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");
	tmp = getIntersectionNode2(p1, p2);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");
	tmp = getIntersectionNode2(p10, p2);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");
	return 0;
}