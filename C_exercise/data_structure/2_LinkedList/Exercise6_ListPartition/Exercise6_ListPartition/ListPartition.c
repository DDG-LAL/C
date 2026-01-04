#define _CRT_SECURE_NO_WARNINGS 1
//【链表分割】
//给出一链表的头指针ListNode* pHead，以及一个定值x
//将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序
//返回排列后的链表的头指针

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

ListNode* partition(ListNode* pHead, int x)
{
	ListNode* big = (ListNode*)malloc(sizeof(ListNode)); //哨兵位头结点
	assert(big);
	big->next = NULL;
	ListNode* small = (ListNode*)malloc(sizeof(ListNode)); //哨兵位头结点
	assert(small);
	small->next = NULL;
	ListNode* cur = pHead, * btail = big, * stail = small;

	while (cur)
	{
		ListNode* tmp = cur->next;
		cur->next = NULL; //避免出现带环链表
		if (cur->val < x)
		{
			stail->next = cur; //小于x的结点尾插small链表
			stail = stail->next;
		}
		else
		{
			btail->next = cur; //不小于x的结点尾插big链表
			btail = btail->next;
		}
		cur = tmp;
	}
	stail->next = big->next; //连接两个链表
	ListNode* del = small;
	small = small->next;
	free(del); //释放哨兵位头结点的空间
	free(big);
	return small;
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
	p2->val = 3;
	p3->val = 5;
	p4->val = 1;
	p5->val = 2;
	p6->val = 8;
	p7->val = 9;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	p7->next = NULL;

	struct ListNode* tmp = partition(p1, 4);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");
	return 0;
}