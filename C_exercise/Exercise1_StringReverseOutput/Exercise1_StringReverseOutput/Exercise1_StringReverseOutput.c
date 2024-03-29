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
    char arr[100] = { 0 };
    gets(arr);  //避免空格不被读取
    reverse_words(arr);
    
    printf("%s\n\n", arr);
    rewind(stdin);  //清理标准输入缓冲区，fflush函数在C11之后(VS2015及之后)已经不支持
    memset(arr, 0, sizeof(arr));  //将数组arr的内容全置为0
    
    scanf("%[^\n]", arr);  //避免空格不被读取
    my_reverse_output(arr);
    return 0;
}


