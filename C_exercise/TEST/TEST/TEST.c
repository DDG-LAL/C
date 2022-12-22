#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

void reverse_output(char* arr)
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
            arr--;
        }
    }
}

int main()
{
    char arr[100] = { 0 };
    gets(arr);
    printf("\n%s\n\n", arr);
    //scanf("%[^\n]", arr);
  /*  char a;
    while (getchar() != EOF)
    {
        ;
    }*/
    //arr[3] = '2';
    //scanf("%[^\n]", arr);
    reverse_output(arr);
    //printf("\n\n%s", arr);
    return 0;
}


