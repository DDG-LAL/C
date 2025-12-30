#define _CRT_SECURE_NO_WARNINGS 1
//【移除链表指定元素】
//给出一个链表的头节点head和一个整数val
//要求删除链表中所有满足Node.val == val的节点，并返回新的头节点

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

//遍历一次，若符合条件则尾插到新链表
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* cur = head;
	struct ListNode* newhead = NULL;
	struct ListNode* tail = newhead;

	while (cur)
	{
		if (cur->val == val)
		{
			struct ListNode* del = cur;
			cur = cur->next;
			free(del);
		}
		else
		{
			if (!newhead)
			{
				tail = newhead = cur;
				cur = cur->next;
			}
			else
			{
				tail->next = cur;
				cur = cur->next;
				tail = tail->next;
			}
		}
	}
	if (tail)
		tail->next = NULL;
	return newhead;
}

int main()
{
	struct ListNode* p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p7 = (struct ListNode*)malloc(sizeof(struct ListNode));
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


	struct ListNode* tmp = removeElements(p1, 6);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");

	return 0;
}