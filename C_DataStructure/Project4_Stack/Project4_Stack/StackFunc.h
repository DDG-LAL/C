#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STdatatype;

typedef struct Stack
{
	STdatatype* data;
	int top;
	int cap;
}ST;

void STinit(ST* pst); //初始化

bool STempty(ST* pst); //判断栈是否为空

void STpush(ST* pst, STdatatype x); //入栈
void STpop(ST* pst); //出栈

STdatatype STtop(ST* pst); //获取栈顶元素

int STsize(ST* pst); //获取栈内元素个数

void STdestroy(ST* pst); //销毁
