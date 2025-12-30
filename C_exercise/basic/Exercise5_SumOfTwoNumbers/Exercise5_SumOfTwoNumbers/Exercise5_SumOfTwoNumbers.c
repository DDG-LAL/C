#define _CRT_SECURE_NO_WARNINGS 1
//【两数之和】
//给定一个整数数组nums和一个整数目标值target，
//在该数组中找出和为目标值target的两个整数，并返回它们的数组下标。
//可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//可以按任意顺序返回答案。

#include<stdio.h>
#include<stdlib.h>
//#include"uthash.h"

//法1：双层循环直接遍历
int* twoSum1(int* nums, int numsSize, int target, int* returnSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)  //发现两个数字的和等于目标值
            {
                int* ret = (int*)malloc(2 * sizeof(int));  //定义一个储存下标值的指针
                ret[0] = i;  //将下标值存储到指针中
                ret[1] = j;
                *returnSize = 2;  //返回长度2
                return ret;  //返回储存下标值的指针
            }                //returnSize的值是给外部接口用的，用来告知返回数组的长度
        }
    }
    *returnSize = 0;  //返回长度0
    return NULL; // 如果找不到两个数字的和等于目标值，返回空指针
}

//法2：哈希表
//struct hashTable {
//    int key;
//    int val;
//    UT_hash_handle hh;
//};
//
//struct hashTable* hashtable;
//
//struct hashTable* find(int ikey) {
//    struct hashTable* tmp;
//    HASH_FIND_INT(hashtable, &ikey, tmp);
//    return tmp;
//}
//
//void insert(int ikey, int ival) {
//    struct hashTable* it = find(ikey);
//    if (it == NULL) {
//        struct hashTable* tmp = malloc(sizeof(struct hashTable));
//        tmp->key = ikey, tmp->val = ival;
//        HASH_ADD_INT(hashtable, key, tmp);
//    }
//    else {
//        it->val = ival;
//    }
//}
//
//int* twoSum2(int* nums, int numsSize, int target, int* returnSize) {
//    hashtable = NULL;
//    for (int i = 0; i < numsSize; i++) {
//        struct hashTable* it = find(target - nums[i]);
//        if (it != NULL) {
//            int* ret = malloc(sizeof(int) * 2);
//            ret[0] = it->val, ret[1] = i;
//            *returnSize = 2;
//            return ret;
//        }
//        insert(nums[i], i);
//    }
//    *returnSize = 0;
//    return NULL;
//}

int main()
{
    int a[] = { 8, 2, 3, 4, 9 };
    int rsize1 = 0, rsize2 = 0;
    int* r1 = twoSum1(a, sizeof(a) / sizeof(a[0]), 6, &rsize1);
    //int* r2 = twoSum2(a, sizeof(a) / sizeof(a[0]), 6, &rsize2);
    printf("%d %d", r1[0], r1[1]);
    //printf("%d %d", r2[0], r2[1]);
    return 0;
}
