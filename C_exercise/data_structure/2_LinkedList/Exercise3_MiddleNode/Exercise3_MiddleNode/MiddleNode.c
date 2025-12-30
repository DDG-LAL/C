#define _CRT_SECURE_NO_WARNINGS 1
//【链表的中间结点】
//给出单链表的头指针head，要求找出并返回链表的中间结点。
//若有两个中间结点，则返回第二个中间结点。
//示例：
//输入：head = [1, 2, 3, 4, 5]
//输出：[3, 4, 5]

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head)
{
	//快慢指针
	//fast一次走两步，slow一次走一步
	//fast到达链表尾时，slow到达链表中间
	struct ListNode* fast = head, * slow = head; 

	while (fast && fast->next) //结点数为奇数时fast到达尾节点，结点数为偶数时fast到达NULL
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
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


	struct ListNode* tmp = middleNode(p1);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");
	tmp = middleNode(p2);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");

	return 0;
}