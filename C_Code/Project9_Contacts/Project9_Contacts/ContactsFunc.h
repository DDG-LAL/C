#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define CONTACT_MAX 500  //ͨѶ¼����
#define NAME_MAX 20
#define MOBILE_MAX 12
#define ADDR_MAX 20

enum  //ö�ٸ��ֹ���
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};

typedef enum gender  //ö���Ա�
{
	SECRET,
	MALE,
	FEMALE
}gender;

typedef struct ContactInfo  //������ϵ�˽ṹ��������ϵ�˵ĸ�����Ϣ����
{
	char name[NAME_MAX];
	int age;
	gender gen;
	char mobile[MOBILE_MAX];
	char addr[ADDR_MAX];
}Info;

typedef struct Contact  //ͨѶ¼�ṹ�����������ϵ�ˣ��Լ���¼��ϵ������������
{
	Info peo[CONTACT_MAX];
	int sz;
}Con;

int choose(int l, int r);  //ѡ��ѡ��
void InitContacts(Con* p);  //��ʼ��ͨѶ¼
void AddContact(Con* p);  //�����ϵ��