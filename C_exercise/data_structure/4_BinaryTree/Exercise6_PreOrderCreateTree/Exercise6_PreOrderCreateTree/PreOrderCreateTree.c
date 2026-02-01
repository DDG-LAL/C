#define _CRT_SECURE_NO_WARNINGS 1
//【建立二叉树并遍历】
//读取输入的一串先序遍历字符串(字符串中'#'字符代表空树)，根据此字符串建立一个二叉树，以指针方式存储
//建立二叉树后，对二叉树进行中序遍历，输出遍历结果
//示例:
//输入: abc##de#g##f### 
//输出: c b e g d f a

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef char BTdatatype;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTdatatype val;
}BTnode;

BTnode* BuyNode(BTdatatype x)
{
	BTnode* newnode = (BTnode*)malloc(sizeof(BTnode));
	if (!newnode)
	{
		perror("malloc\n");
		return NULL;
	}
	newnode->left = newnode->right = NULL;
	newnode->val = x;
	return newnode;
}

void BTdestroy(BTnode* root)
{
	if (!root)
		return;
	BTdestroy(root->left);
	BTdestroy(root->right);
	free(root);
}

BTnode* PreOrderCreateTree(BTdatatype* arr, int* i)
{
	if (arr[*i] == '#') //若为空节点，返回NULL
	{
		(*i)++;
		return NULL;
	}
	BTnode* newnode = BuyNode(arr[(*i)++]); //若不为空节点，先创建当前节点，再递归创建当前节点的子节点，再返回当前节点
	newnode->left = PreOrderCreateTree(arr, i);
	newnode->right = PreOrderCreateTree(arr, i);
	return newnode;
}

void PrintInOrder(BTnode* root)
{
	if (!root)
		return;
	PrintInOrder(root->left);
	printf("%c ", root->val);
	PrintInOrder(root->right);
}

int main()
{
	char input[100] = { 0 };
#pragma warning(push)
#pragma warning(disable:6031)
	scanf("%s", &input);
#pragma warning(pop)
	int i = 0;
	BTnode* root = PreOrderCreateTree(input, &i);
	PrintInOrder(root);
	BTdestroy(root);
	return 0;
}