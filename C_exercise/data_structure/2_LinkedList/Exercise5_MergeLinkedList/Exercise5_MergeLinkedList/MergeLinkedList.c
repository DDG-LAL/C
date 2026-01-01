#define _CRT_SECURE_NO_WARNINGS 1
//【合并两个有序链表】
//将两个升序链表合并为一个新的升序链表并返回
//新链表由给定的两个链表的所有节点组成
//示例：
//输入：l1 = [1, 2, 4], l2 = [1, 3, 4]
//输出：[1, 1, 2, 3, 4, 4]

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) //取较小值在新的位置尾插
{
	/*if (!list1)      //处理其中一个链表为空的情况
		return list2;
	if (!list2)
		return list1;*/
	struct ListNode* head = NULL, * cur = NULL, * p1 = list1, * p2 = list2;
	while (p1 && p2)
	{
		if (p1->val < p2->val)
		{
			if (!head) //若新的头结点为空，则需要初始化
				cur = head = p1;
			else
			{
				cur->next = p1;
				cur = cur->next;
			}
			p1 = p1->next;
		}
		else
		{
			if (!head) //若新的头结点为空，则需要初始化
				cur = head = p2;
			else
			{
				cur->next = p2;
				cur = cur->next;
			}
			p2 = p2->next;
		}
	}
	if (p1)
		p2 = p1;
	if (p2)
		if (!head) //其中一个是空链表的情况，直接返回另一个链表的头指针
			head = p2;
		else
			cur->next = p2;
	return head;
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
	p2->val = 3;
	p3->val = 5;
	p4->val = 7;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = NULL;

	p5->val = 2;
	p6->val = 8;
	p7->val = 9;
	p5->next = p6;
	p6->next = p7;
	p7->next = NULL;

	struct ListNode* tmp = mergeTwoLists(p1, p5);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");
	return 0;
}