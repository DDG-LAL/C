#define _CRT_SECURE_NO_WARNINGS 1
//【回文链表】
//给定一个链表的头指针A，要求返回一个bool值，表示其是否为回文结构

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

ListNode* midnode(ListNode* phead) //找到中间节点
{
	ListNode* fast, * slow;
	fast = slow = phead;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

ListNode* reverse(ListNode* phead) //逆置
{
	ListNode* cur = NULL, * next = phead, * end = phead->next;
	while (next)
	{
		next->next = cur;
		cur = next;
		next = end;
		if (end)
			end = end->next;
	}
	return cur;
}

bool chkPalindrome(ListNode* phead) //找到中间节点，然后将链表后半段逆置，再进行比对
{
	if (!phead)
		return false;
	if (!phead->next)
		return true;
	ListNode* mid = midnode(phead);
	ListNode* tmp = reverse(mid);
	while (tmp) //比对
	{
		if (phead->val == tmp->val)
		{
			phead = phead->next;
			tmp = tmp->next;
		}
		else
			return false;
	}
	return true;
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
	p1->val = 7;
	p2->val = 5;
	p3->val = 9;
	p4->val = 1;
	p5->val = 9;
	p6->val = 5;
	p7->val = 7;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	p7->next = NULL;

	if (chkPalindrome(p1))
		printf("true\n");
	else
		printf("false\n");
	printf("\n");

	p1->val = 7;
	p2->val = 5;
	p3->val = 1;
	p4->val = 1;
	p5->val = 5;
	p6->val = 7;
	p7->val = 7;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = NULL;
	p7->next = NULL;

	if (chkPalindrome(p1))
		printf("true\n");
	else
		printf("false\n");
	printf("\n");

	p1->val = 7;
	p2->val = 5;
	p3->val = 1;
	p4->val = 2;
	p5->val = 5;
	p6->val = 7;
	p7->val = 7;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = NULL;
	p7->next = NULL;

	if (chkPalindrome(p1))
		printf("true\n");
	else
		printf("false\n");
	printf("\n");

	return 0;
}