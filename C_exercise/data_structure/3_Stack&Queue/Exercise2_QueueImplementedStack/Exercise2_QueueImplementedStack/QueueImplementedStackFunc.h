#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include"QueueFunc.h"

typedef struct QueueImplementedStack
{
	Queue q1;
	Queue q2;
}MyStack;

MyStack* myStackCreate(); //初始化

void myStackPush(MyStack* obj, int x); //入栈

int myStackPop(MyStack* obj); //出栈

int myStackTop(MyStack* obj); //获取栈顶元素

bool myStackEmpty(MyStack* obj); //判断栈是否为空

void myStackFree(MyStack* obj); //销毁