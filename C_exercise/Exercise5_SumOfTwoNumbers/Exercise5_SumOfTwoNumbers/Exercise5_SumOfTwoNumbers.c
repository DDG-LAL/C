#define _CRT_SECURE_NO_WARNINGS 1
//【两数之和】
//给定一个整数数组nums和一个整数目标值target，
//在该数组中找出和为目标值target的两个整数，并返回它们的数组下标。
//可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//可以按任意顺序返回答案。

#include<stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* ret = (int*)malloc(2 * sizeof(int));  //定义一个储存下标值的指针
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)  //找到两个数字的和等于目标值
            {
                ret[0] = i;  //将下标值存储到指针中
                ret[1] = j;
                *returnSize = 2;  //返回的指针长度应该是2
                return ret;  //返回储存下标值的指针
            }//returnSize的值是给外部接口用的，用来告知返回数组的长度
        }
    }
    return NULL; // 如果找不到两个数字的和等于目标值，返回空指针
}


int main()
{
    int a[] = { 8, 2, 3, 4, 9 };
    int target = 5;
    int rsize = 0;
    int* r = twoSum(a, sizeof(a) / sizeof(a[0]), 6, &rsize);
    printf("%d %d", r[0], r[1]);
    return 0;
}
