#define _CRT_SECURE_NO_WARNINGS 1
//【移除链表指定元素】
//给出一个链表的头结点head和一个整数val
//要求删除链表中所有满足Node.val == val的结点，并返回新的头结点
//示例：
//输入：head = [1, 2, 6, 3, 4, 5, 6], val = 6
//输出：[1, 2, 3, 4, 5]

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

//遍历一次，若符合条件则尾插到新链表
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* cur = head; //用于遍历
	struct ListNode* newhead = NULL; //新头指针，用于返回
	struct ListNode* tail = newhead; //尾指针，辅助新链表的尾插

	while (cur)
	{
		if (cur->val == val) //若等于val，则删除结点
		{
			struct ListNode* del = cur;
			cur = cur->next;
			free(del);
			if (tail) //若新链表为空，则tail==NULL，不能访问tail->next
				tail->next = NULL; 
				//若新链表非空，则此时tail->next指向的是已经被free的del空间，要置空，否则产生野指针
		}
		else //若不等于val，尾插
		{
			if (!newhead) //若新头指针为空，由第一个非val结点确定新头指针
				tail = newhead = cur; //尾指针和头指针都指向第一个结点
			else //头指针不为空，直接尾插
			{
				tail->next = cur; //将新链表尾结点链接到当前结点
				tail = tail->next; //tail重新指向新链表尾结点
			}
			cur = cur->next; //cur指向下一结点
		}
	}
	return newhead;
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


	struct ListNode* tmp = removeElements(p1, 6);
	while (tmp)
	{
		printf("%d->", tmp->val);
		tmp = tmp->next;
	}
	printf("NULL\n");

	return 0;
}