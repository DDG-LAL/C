#define _CRT_SECURE_NO_WARNINGS 1
//【链表倒数第k个结点】
//输入一个链表以及一个整数k，输出该链表中倒数第k个结点
//示例：
//输入：1, { 1,2,3,4,5 }
//输出：{ 5 }

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) //快慢指针
{
	struct ListNode* p1 = pListHead, * p2 = pListHead; 
	while (k)						 //p2先走k次，然后p1和p2同步向链表尾部走			   
	{								 //当p2到达链表尾的空指针，则p1到达倒数第k个结点
		if (!p2) return NULL; //若p2在到达链表尾的时候还未走到k步，说明k>链表长度，返回空指针
		p2 = p2->next;
		k--;
	}
	while (p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
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
	p6->val = 6;
	p7->val = 7;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	p7->next = NULL;

	struct ListNode* tmp = FindKthToTail(p1, 5);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");
	return 0;
}