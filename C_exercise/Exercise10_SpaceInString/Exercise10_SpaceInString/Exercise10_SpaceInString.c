#define _CRT_SECURE_NO_WARNINGS 1
//���ո��滻Ϊ%20��
//ʵ��һ����������һ���ַ����е�ÿ���ո��滻��"%20"
//�磺���ַ���Ϊ"I am"����������Ϊ"I%20am"

#include<stdio.h>
#include<string.h>

void func20_1(char* str)  //Ч�ʽϵ͵ķ���
{
	int len = strlen(str);
	char* r = str + len - 1;
	char* p = NULL;
	while ((p = strstr(str, " ")) != NULL)  //���ո��λ�ô����ָ��p��
	{
		*(r + 3) = '\0';  //���ַ���ĩβ����ƶ������ֽ�
		while (r > p)  //���ո�֮��������ַ�������ƶ������ֽ�
		{
			*(r + 2) = *r;
			--r;
		}
		*p = '%';  //�ڿո��λ��д��"%20"
		*(p + 1) = '2';
		*(p + 2) = '0';
		len += 2;  //��������2
		r = str + len - 1;  //�����ַ���ĩβָ��
	}
}

void func20_2(char* str)  //Ч�ʽϸߵķ���
{
	int spacenum = 0;
	char* p = str;
	while (*p != '\0')  //��¼�ո������
	{
		if (*p == ' ')
			++spacenum;
		++p;
	}
	--p;  //��ʱָ��pָ�����ǰ���ַ���ĩβλ��
	char* end = p + 2 * spacenum;  //ȷ����������ַ���ĩβָ���λ��
	while (end != p)
	{
		if (*p == ' ')  //�����ո�ʱ��end��д��"%20"��pֱ��ָ����һ��λ��
		{
			*end-- = '0';
			*end-- = '2';
			*end-- = '%';
			--p;
		}
		else  //δ�����ո�ʱ���ַ���p�����Ƶ�end��
			*end-- = *p--;
	}
}

int main()
{
	char a[30] = "asd qwee rer";
	char b[30] = "asd qwee rer";
	func20_1(a);
	func20_2(b);
	printf(a);
	printf("\n\n");
	printf(b);
	printf("\n\n");
	printf("asd%20qwee%20rer\n\n");
	printf("asd%%20qwee%%20rer\n");  //������ӡ'%'�����ⱻʶ��Ϊ��ʽ˵����
	return 0;
}

