#define _CRT_SECURE_NO_WARNINGS 1
//�������ַ�������һ�仰�ĵ��ʽ��е��ã���㲻���á�
//
//����������
//ÿ�������������1������������ I like beijing.�����������Ȳ�����100
//���������
//�����������֮����ַ���, �Կո�ָ�
//ʾ����
//���룺I like beijing.
//�����beijing.like I

#include<stdio.h>
#include<string.h>

void my_reverse_output(char* arr)  //��һ�仰�ԡ����ʵ��ã���㲻���á�����ʽ���
{
    int len = strlen(arr); 
    char* left = arr;
    arr += (len - 1);
    while (1)
    {
        if (arr == left)
        {
            printf("%s", arr);
            break;
        }
        if (*arr == ' ')
        {
            printf("%s ", arr + 1);
            *arr = '\0';
            arr--;
        }
        else
        {
            arr--;  //��������Ѱ�ҿո�
        }
    }
}

void reverse(char* left, char* right)  //��һ���ַ�������
{
    char buf = 0;
    while (right > left)
    {
        buf = *left;
        *left = *right;
        *right = buf;
        ++left;
        --right;
    }
}

void reverse_words(char* str)  //��һ�仰�ĵ��ʵ��ã���㲻���ã���ԭ�ַ������޸�
{
    int len = strlen(str);
    char* l = str;
    char* r = str + len - 1;
    reverse(l, r);
    r = str;
    while (*r != '\0')
    {
        while (*r != ' ' && *r != '\0')
            ++r;
        reverse(l, r - 1);
        l = ++r;
    }
}

int main()
{
    char arr1[100] = { 0 };
    gets(arr1);  //����ո񲻱���ȡ
    reverse_words(arr1);
    printf("%s\n\n", arr1);

    char arr2[100] = { 0 };
    scanf("%[^\n]", arr2);  //����ո񲻱���ȡ
    my_reverse_output(arr2);
    return 0;
}


