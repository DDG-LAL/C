#define _CRT_SECURE_NO_WARNINGS 1
//【相交链表】
//给出两个不带环单链表的头节点headA和headB，要求找出并返回两个单链表相交的起始节点
//若两个链表不存在相交节点，则返回NULL
//函数返回结果后，要求链表必须保持其原始结构

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

struct ListNode* getIntersectionNode1(struct ListNode* headA, struct ListNode* headB)
{
	if (!headA || !headB)
		return NULL;
	struct ListNode* tailA = headA, * tailB = headB;
	while (tailB->next)
		tailB = tailB->next; //找尾
	while (tailA->next)
		tailA = tailA->next; //找尾
	if (tailA != tailB) //若尾节点不同，说明没有交点
		return NULL;
	tailB->next = headA; //已经确定有交点，制造一个环，则入环点即为交点
	struct ListNode* fast = headB, * slow = headB;
	while (fast && fast->next) //Floyd判圈算法，使用快慢指针
	{						   //快指针先进环，慢指针后进环，步长之差为1
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) //若两指针相遇则存在环
			break;
	}
	fast = headB; //Floyd判圈算法确定入环点，设起始点至入环点距离L，入环点至相遇点距离a，相遇点至入环点距离b
	while (fast != slow)   //快慢指针阶段：到相遇时候为止，快指针路程为S1 = L+n(a+b)+a，慢指针路程为S2 = L+a
	{					   //因快指针速度为2，慢指针速度为1，得S1=2*S2，L+n(a+b)+a = 2*L+2*a，L = n(a+b)-a
		fast = fast->next; //而n(a+b)-a = (n-1)(a+b)+b，因此从相遇点开始走出距离L = n(a+b)-a时，正好走到入环点
		slow = slow->next; //综上，令fast从head开始，slow从相遇点开始，两个指针同步走，相遇时正好会在入环点
	}
	tailB->next = NULL;
	return fast;
}

struct ListNode* getIntersectionNode2(struct ListNode* headA, struct ListNode* headB) //长链表先走差距步，然后两个链表指针同步走
{
	if (!headA || !headB)
		return NULL;
	struct ListNode* tailA = headA, * tailB = headB;
	int countA = 1, countB = 1, gap = 0;
	while (tailA->next)
	{
		tailA = tailA->next; //找尾
		countA++; //记录长度
	}
	while (tailB->next)
	{
		tailB = tailB->next; //找尾
		countB++; //记录长度
	}
	if (tailA != tailB) //若尾节点不同，则没有交点
		return NULL;
	if (countB > countA) //强行使A为长链表，使B为短链表
	{
		struct ListNode* tmp = headA;
		headA = headB;
		headB = tmp;
	}
	gap = abs(countA - countB); //计算差距步
	while (gap--)
		headA = headA->next; //长链表指针先走差距步
	while (headA != headB)
	{
		assert(headA && headB); //避免C28182警告
		headA = headA->next;
		headB = headB->next; //两个链表指针同步走
	}
	return headA;
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
	p9->val = 10;
	p10->val = 11;

	p1->next = p3;
	p3->next = p5;
	p5->next = p7;
	p7->next = p9;

	p2->next = p4;
	p4->next = p6;
	p6->next = p8;
	p8->next = p9;

	p9->next = p10;
	p10->next = NULL;

	struct ListNode* tmp;
	tmp = getIntersectionNode1(p1, p2);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");
	tmp = getIntersectionNode1(p10, p2);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");
	tmp = getIntersectionNode2(p1, p2);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");
	tmp = getIntersectionNode2(p10, p2);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");
	return 0;
}