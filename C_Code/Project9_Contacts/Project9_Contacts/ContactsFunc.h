#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define CONTACT_MAX 500  //通讯录容量
#define NAME_MAX 20
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
	PRINT
};

typedef enum gender  //枚举性别
{
	SECRET,
	MALE,
	FEMALE
}gender;

typedef struct ContactInfo  //单个联系人结构，包含联系人的各种信息类型
{
	char name[NAME_MAX];
	int age;
	gender gen;
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