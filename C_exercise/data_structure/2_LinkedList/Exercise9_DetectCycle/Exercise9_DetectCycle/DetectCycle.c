#define _CRT_SECURE_NO_WARNINGS 1
//【带环链表】
//给出一个链表的头节点head，要求判断链表中是否有环
//若链表中有某个节点，可以通过连续跟踪next指针再次到达，则链表中存在环
//如果链表中存在环，则返回true，否则返回false
//【检测入环点】
//给出一个链表的头节点head，要求返回链表开始入环的第一个节点，若链表无环，则返回NULL

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

//Floyd判圈算法判断链表是否带环
bool hasCycle(struct ListNode* head) //速度为2的快指针和速度为1的慢指针同时从链表头结点开始向后遍历
{									 //若存在环，则快指针先进环，慢指针后进环，快指针会在环内从后方追上慢指针
	if (!head)						 //因此若两指针能相遇则说明有环，若任一指针走到空指针则说明没有环
		return false;				 //因为速度差为1，所以不存在快指针在环内跳过慢指针导致不相遇的情况
	struct ListNode* fast = head, * slow = head; //快慢指针起点均为head
	while (fast && fast->next && slow) //任一指针为空都说明没有环
	{
		fast = fast->next->next; //快指针速度为2
		slow = slow->next;		 //慢指针速度为1
		if (fast == slow)		 //相遇说明有环
			return true;
	}
	return false;
}
//Floyd判圈算法确定入环点
struct ListNode* detectCycle1(struct ListNode* head) //设起始点至入环点距离L，入环点至相遇点距离a，相遇点至入环点距离b
{													//快慢指针阶段：到相遇时候为止，快指针路程为S1 = L+n(a+b)+a，慢指针路程为S2 = L+a
	if (!head || !head->next)						//因快指针速度为2，慢指针速度为1，得S1=2*S2，L+n(a+b)+a = 2*L+2*a，L = n(a+b)-a
		return NULL;								//而n(a+b)-a = (n-1)(a+b)+b，因此从相遇点开始走出距离L = n(a+b)-a时，正好走到入环点
	struct ListNode* fast = head, * slow = head;	//综上，令fast从head开始，slow从相遇点开始，两个指针同步走，相遇时正好会在入环点
	while (fast && fast->next && slow)
	{
		fast = fast->next->next; //快指针速度为2
		slow = slow->next;		 //慢指针速度为1
		if (fast == slow)
			break;
	}
	if (!fast || !slow || !fast->next) //任一指针为空都说明没有环
		return NULL;
	fast = head; //令fast指向head
	while (fast != slow)
	{
		fast = fast->next; //两指针同步走
		slow = slow->next;
	}
	return fast;
}

struct ListNode* detectCycle2(struct ListNode* head) //将问题转化为寻找链表交点
{
	if (!head || !head->next)
		return NULL;
	struct ListNode* fast = head, * slow = head;
	while (fast && fast->next && slow)
	{
		fast = fast->next->next; //快慢指针判断是否有环
		slow = slow->next;
		if (fast == slow) //能相遇说明有环
		{
			struct ListNode* meet = fast->next, * buf = fast->next;
			struct ListNode* meettail = meet, * headtail = head;
			int lmeet = 1, lhead = 1, gap = 0;
			fast->next = NULL; //断开环，将问题转化为寻找链表交点
			while (meettail->next)
			{
				meettail = meettail->next;
				lmeet++; //记录meet链表长度
			}
			while (headtail->next)
			{
				headtail = headtail->next;
				lhead++; //记录head链表长度
			}
			gap = abs(lmeet - lhead);
			if (lmeet > lhead) //强行使head链表为长链表
			{
				struct ListNode* tmp = meet;
				meet = head;
				head = tmp;
			}
			while (gap--)
				head = head->next; //令head指针先走差距步
			while (head != meet)   //两个指针同步走，在交点相遇
			{
				assert(meet); //避免C28182警告
				head = head->next;
				meet = meet->next;
			}
			fast->next = buf; //将断开处还原
			return meet;
		}
	}
	return NULL;
}

void test1(struct ListNode* p1) //测试
{
	struct ListNode* tmp;
	if (hasCycle(p1))
	{
		printf("true\n");
		int n = 20;
		tmp = detectCycle1(p1);
		while (n--)
		{
			printf("%d->", tmp->val);
			tmp = tmp->next;
		}
		printf("\b\b  ");
	}
	else
	{
		tmp = detectCycle1(p1);
		if (!tmp)
			printf("false\n");
	}
	printf("\n\n");
}

void test2(struct ListNode* p1) //测试
{
	struct ListNode* tmp;
	if (hasCycle(p1))
	{
		printf("true\n");
		int n = 20;
		tmp = detectCycle2(p1);
		while (n--)
		{
			printf("%d->", tmp->val);
			tmp = tmp->next;
		}
		printf("\b\b  ");
	}
	else
	{
		tmp = detectCycle2(p1);
		if (!tmp)
			printf("false\n");
	}
	printf("\n\n");
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
	p9->val = 9;
	p10->val = 10;

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	p7->next = p8;
	p8->next = p9;
	p9->next = p10;

	p10->next = p6;
	test1(p1);
	test2(p1);
	p10->next = p10;
	test1(p1);
	test2(p1);
	p10->next = NULL;
	test1(p1);
	test2(p1);
	p10->next = p1;
	test1(p1);
	test2(p1);
	p1->next = p1;
	test1(p1);
	test2(p1);

	return 0;
}