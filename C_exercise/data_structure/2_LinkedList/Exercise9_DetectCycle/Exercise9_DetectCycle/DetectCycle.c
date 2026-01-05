#define _CRT_SECURE_NO_WARNINGS 1
//【带环链表】
//给出一个链表的头节点head，要求判断链表中是否有环
//若链表中有某个节点，可以通过连续跟踪next指针再次到达，则链表中存在环
//如果链表中存在环，则返回true，否则返回false
//【检测入环点】
//给出一个链表的头节点head，要求返回链表开始入环的第一个节点，若链表无环，则返回NULL

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

bool hasCycle(struct ListNode* head)
{
	if (!head)
		return false;
	struct ListNode* fast = head, * slow = head;
	while (fast && fast->next && slow)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}

struct ListNode* detectCycle(struct ListNode* head)
{
	if (!head || !head->next)
		return NULL;
	struct ListNode* fast = head, * slow = head;
	while (fast && fast->next && slow)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			break;
	}
	if (!fast || !slow || !fast->next)
		return NULL;
	fast = head;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}

void test(struct ListNode* p1)
{
	struct ListNode* tmp;
	if (hasCycle(p1))
	{
		printf("true\n");
		int n = 20;
		tmp = detectCycle(p1);
		while (n--)
		{
			printf("%d->", tmp->val);
			tmp = tmp->next;
		}
		printf("\b\b  ");
	}
	else
	{
		tmp = detectCycle(p1);
		if (!tmp)
			printf("false\n");
	}
	printf("\n\n");
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
	p9->val = 9;
	p10->val = 10;

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	p7->next = p8;
	p8->next = p9;
	p9->next = p10;

	p10->next = p6;
	test(p1);
	p10->next = p10;
	test(p1);
	p10->next = NULL;
	test(p1);
	p10->next = p1;
	test(p1);
	p1->next = p1;
	test(p1);

	return 0;
}