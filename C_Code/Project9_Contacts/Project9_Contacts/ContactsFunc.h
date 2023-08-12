#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define CONTACT_MAX 10  //通讯录容量
#define NAME_MAX 20
#define GEN_MAX 10
#define MOBILE_MAX 12
#define ADDR_MAX 20

enum  //枚举各种功能
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT,
	CLEAR
};

typedef struct ContactInfo  //单个联系人结构，包含联系人的各种信息类型
{
	int num;
	char name[NAME_MAX];
	int age;
	char gen[GEN_MAX];
	char mobile[MOBILE_MAX];
	char addr[ADDR_MAX];
}Info;

typedef struct Contact  //通讯录结构，包含多个联系人，以及记录联系人数量的整型
{
	Info peo[CONTACT_MAX];
	int sz;
}Con;

int choose(int l, int r);  //选项选择

void InitContacts(Con* p);  //初始化通讯录
void AddContact(Con* p);  //添加联系人
void PrintContact(const Con* p, int l, int r);  //打印通讯录

void SearchContact(const Con* p);  //搜索联系人，成功则打印
void DelContact(Con* p);  //删除指定联系人
void ModifyContact(Con* p);  //修改指定联系人
void SortContact(Con* p);  //排序联系人
void ClearContact(Con* p);  //清空通讯录
