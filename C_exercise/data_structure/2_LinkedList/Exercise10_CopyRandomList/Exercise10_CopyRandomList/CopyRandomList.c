#define _CRT_SECURE_NO_WARNINGS 1
//【复制随机链表】
//给出一个长度为n的链表，每个节点包含一个额外增加的随机指针random，该指针可能指向链表中的任何节点或空节点
//要求构造这个链表的深拷贝
//深拷贝应该正好由n个全新节点组成，其中每个新节点的值都设为其对应的原节点的值
//新节点的next指针和random指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态
//复制链表中的指针不应指向原链表中的节点
//返回复制链表的头节点

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
};

struct Node* BuyNode(int x) //创建新结点
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	if (!newnode)
	{
		perror("malloc\n");
		return NULL;
	}
	newnode->val = x;
	newnode->random = NULL;
	newnode->next = NULL;
	return newnode;
}

struct Node* copyRandomList(struct Node* head) //在原链表的每个结点后插入一个复制结点
{											   //利用复制结点与原链表结点的位置关系确定复制结点的random
	if (!head)								   //确定random的值后分离出新结点和旧结点，形成新旧两个相同链表，返回新链表
		return NULL;
	struct Node* cur = head, * next = head->next;
	while (cur) //在原链表的每个结点后插入一个复制结点
	{
		struct Node* newnode = BuyNode(cur->val); //复制结点的val值与原链表相同
		newnode->next = next;
		cur->next = newnode;
		cur = next;
		if (next) //避免越界
			next = next->next;
	}
	cur = head;
	next = head->next;
	while (cur) //利用复制结点与原链表结点的位置关系确定复制结点的random
	{
		next->random = cur->random ? cur->random->next : NULL; //若原结点random值不为NULL，则新结点random值为原结点的random指向的结点的next
		cur = cur->next->next;
		if (next->next) //避免越界
		{
			assert(next->next); //避免C28182警告
			next = next->next->next;
		}
	}
	struct Node* newhead = head->next; //保存新链表头结点
	struct Node* pre = head;
	cur = head->next;
	assert(head->next); //避免C28182警告
	next = head->next->next;
	assert(cur->next); //避免C28182警告
	while (cur->next) //新链表和旧链表分离
	{
		pre->next = next;
		cur->next = next ? next->next : NULL; //若next不为NULL，则新结点的next指针指向next->next
		pre = next;
		if (next) //避免越界
		{
			cur = next->next;
			next = next->next->next;
		}
	}
	return newhead;
}

void printNode(struct Node* head) //打印
{
	assert(head);
	struct Node* cur = head;
	while (cur)
	{
		if (cur->random)
			printf("[%d->%d] -> ", cur->val, cur->random->val);
		else
			printf("[%d->NULL] -> ", cur->val);
		cur = cur->next;
	}
	printf("NULL\n\n");
}

int main()
{
	struct Node* p1 = (struct Node*)malloc(sizeof(struct Node));
	assert(p1);
	struct Node* p2 = (struct Node*)malloc(sizeof(struct Node));
	assert(p2);
	struct Node* p3 = (struct Node*)malloc(sizeof(struct Node));
	assert(p3);
	struct Node* p4 = (struct Node*)malloc(sizeof(struct Node));
	assert(p4);
	struct Node* p5 = (struct Node*)malloc(sizeof(struct Node));
	assert(p5);
	struct Node* p6 = (struct Node*)malloc(sizeof(struct Node));
	assert(p6);
	struct Node* p7 = (struct Node*)malloc(sizeof(struct Node));
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

	p1->random = p4;
	p2->random = p2;
	p3->random = p7;
	p4->random = NULL;
	p5->random = p1;
	p6->random = p2;
	p7->random = p3;

	printNode(p1);

	struct Node* tmp = copyRandomList(p1);
	printNode(tmp);

	return 0;
}
