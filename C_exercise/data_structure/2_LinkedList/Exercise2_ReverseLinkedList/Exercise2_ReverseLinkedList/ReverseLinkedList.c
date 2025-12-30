#define _CRT_SECURE_NO_WARNINGS 1
//【反转链表】
//给出单链表的头指针head，要求反转链表，并返回反转后的链表
//示例：
//输入：head = [1, 2, 3, 4, 5]
//输出：[5, 4, 3, 2, 1]

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head)
{
	if (!head || !head->next)
		return head;
	struct ListNode* cur = head, * next = head->next, * end = head->next->next;
	cur->next = NULL;
	while (end)
	{
		next->next = cur;
		cur = next;
		next = end;
		end = end->next;
	}
	next->next = cur;
	return next;
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
	p1->val = 1;
	p2->val = 2;
	p3->val = 6;
	p4->val = 3;
	p5->val = 4;
	p6->val = 5;
	p7->val = 6;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	p7->next = NULL;

	struct ListNode* tmp = reverseList(p1);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");

	return 0;
}