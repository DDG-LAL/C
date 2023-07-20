#define _CRT_SECURE_NO_WARNINGS 1
//【倒置字符串】将一句话的单词进行倒置，标点不倒置。
//
//输入描述：
//每个测试输入包含1个测试用例： I like beijing.输入用例长度不超过100
//输出描述：
//依次输出倒置之后的字符串, 以空格分割
//示例：
//输入：I like beijing.
//输出：beijing.like I

#include<stdio.h>
#include<string.h>

void my_reverse_output(char* arr)  //将一句话以“单词倒置，标点不倒置”的形式输出
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
            arr--;  //从右向左寻找空格
        }
    }
}

void reverse(char* left, char* right)  //将一段字符串倒序
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

void reverse_words(char* str)  //将一句话的单词倒置，标点不倒置，在原字符串上修改
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
    gets(arr1);  //避免空格不被读取
    reverse_words(arr1);
    printf("%s\n\n", arr1);

    char arr2[100] = { 0 };
    scanf("%[^\n]", arr2);  //避免空格不被读取
    my_reverse_output(arr2);
    return 0;
}


