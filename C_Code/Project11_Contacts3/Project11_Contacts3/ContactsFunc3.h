#pragma once
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//静态
//#define CONTACT_MAX 10  //通讯录容量

//动态
#define DEFAULT_CAP 2  //通讯录默认容量
#define DEFAULT_ADD 3  //通讯录扩容容量

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

//静态
//typedef struct Contact  //通讯录结构，包含多个联系人，以及记录联系人数量的整型
//{
//	Info peo[CONTACT_MAX];
//	int sz;
//}Con;

//动态
typedef struct Contacts  //通讯录结构，包含多个联系人，以及记录联系人数量的整型
{
	Info* peo;
	int sz;  //当前已保存的联系人数量
	int cap;  //当前容量
}Con;

int choose(int l, int r);  //选项选择

void InitContacts(Con* p);  //初始化通讯录
void AddContact(Con* p);  //添加联系人
void PrintContacts(const Con* p, int l, int r);  //打印通讯录

void SearchContact(const Con* p);  //搜索联系人，成功则打印
void DelContact(Con* p);  //删除指定联系人
void ModifyContact(Con* p);  //修改指定联系人
void SortContacts(Con* p);  //排序联系人
void ClearContacts(Con* p);  //清空通讯录

//动态
void DeleteContacts(Con* p);  //删除通讯录

//通过文件实现数据存储
void InitDat(Con* p);  //从文件读取数据
void SaveDat(Con* p);  //将数据保存到文件
