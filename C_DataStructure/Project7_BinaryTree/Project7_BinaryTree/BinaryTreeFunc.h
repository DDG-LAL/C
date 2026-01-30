#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"QueueFunc.h"

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

extern int size1; //全局变量用于求节点数
void BTtreesize1(BTnode* root); //全局变量求节点数
int BTtreesize2(BTnode* root); //递归求节点数

int BTleafsize1(BTnode* root); //递归求叶子节点数
int BTleafsize2(BTnode* root); //递归求叶子节点数，三目写法

int BTtreeheight(BTnode* root); //递归求树高度

int BTlevelksize(BTnode* root, int k); //递归求第k层节点数

BTnode* BTfind(BTnode* root, BTdatatype x); //递归查找某个值

void LevelOrder(BTnode* root); //层序遍历(需要队列)