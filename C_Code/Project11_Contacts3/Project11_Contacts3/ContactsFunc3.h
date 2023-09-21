#pragma once
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//��̬
//#define CONTACT_MAX 10  //ͨѶ¼����

//��̬
#define DEFAULT_CAP 2  //ͨѶ¼Ĭ������
#define DEFAULT_ADD 3  //ͨѶ¼��������

#define NAME_MAX 20
#define GEN_MAX 10
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
	PRINT,
	CLEAR
};

typedef struct ContactInfo  //������ϵ�˽ṹ��������ϵ�˵ĸ�����Ϣ����
{
	int num;
	char name[NAME_MAX];
	int age;
	char gen[GEN_MAX];
	char mobile[MOBILE_MAX];
	char addr[ADDR_MAX];
}Info;

//��̬
//typedef struct Contact  //ͨѶ¼�ṹ�����������ϵ�ˣ��Լ���¼��ϵ������������
//{
//	Info peo[CONTACT_MAX];
//	int sz;
//}Con;

//��̬
typedef struct Contacts  //ͨѶ¼�ṹ�����������ϵ�ˣ��Լ���¼��ϵ������������
{
	Info* peo;
	int sz;  //��ǰ�ѱ������ϵ������
	int cap;  //��ǰ����
}Con;

int choose(int l, int r);  //ѡ��ѡ��

void InitContacts(Con* p);  //��ʼ��ͨѶ¼
void AddContact(Con* p);  //�����ϵ��
void PrintContacts(const Con* p, int l, int r);  //��ӡͨѶ¼

void SearchContact(const Con* p);  //������ϵ�ˣ��ɹ����ӡ
void DelContact(Con* p);  //ɾ��ָ����ϵ��
void ModifyContact(Con* p);  //�޸�ָ����ϵ��
void SortContacts(Con* p);  //������ϵ��
void ClearContacts(Con* p);  //���ͨѶ¼

//��̬
void DeleteContacts(Con* p);  //ɾ��ͨѶ¼

//ͨ���ļ�ʵ�����ݴ洢
void InitDat(Con* p);  //���ļ���ȡ����
void SaveDat(Con* p);  //�����ݱ��浽�ļ�
