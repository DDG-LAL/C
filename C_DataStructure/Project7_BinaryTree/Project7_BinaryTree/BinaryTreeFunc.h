#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int BTdatatype;

typedef struct BinaryTreeNode
{
	BTdatatype data;
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;
}BTnode;

BTnode* BuyNode(BTdatatype x); //创建节点

void PreOrder(BTnode* root); //前序遍历
void InOrder(BTnode* root); //中序遍历
void PostOrder(BTnode* root); //后序遍历

