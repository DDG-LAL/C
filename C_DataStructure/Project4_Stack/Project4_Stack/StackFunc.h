#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int STdatatype;

typedef struct Stack
{
	STdatatype* data;
	int top;
	int cap;
}ST;

void STinit(ST* pst); //初始化
void STdesstroy(ST* pst); //销毁

void STpush(ST* pst,STdatatype x); //入栈
void STpop(ST* pst); //出栈
