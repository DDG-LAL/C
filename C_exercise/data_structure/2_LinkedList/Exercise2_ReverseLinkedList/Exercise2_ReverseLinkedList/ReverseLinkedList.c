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

//法1：三指针直接反转，cur和next用于反转前两个节点的指向，end用于迭代以及停止判断
struct ListNode* reverseList1(struct ListNode* head)
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

//法2：从头到尾遍历一次，头插
struct ListNode* reverseList2(struct ListNode* head)
{
	if (!head)
		return head;
	struct ListNode* cur = head, * next = head->next, * rhead = NULL;
	while (cur)
	{
		cur->next = rhead;
		rhead = cur;
		cur = next;
		if (next)
			next = next->next;
	}
	return rhead;
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
	p3->val = 3;
	p4->val = 4;
	p5->val = 5;
	p6->val = 7;
	p7->val = 9;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	p7->next = NULL;

	struct ListNode* tmp = reverseList1(p1);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");

	tmp = reverseList2(p7);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");

	return 0;
}