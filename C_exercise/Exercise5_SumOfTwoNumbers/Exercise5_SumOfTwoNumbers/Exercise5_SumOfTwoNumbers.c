#define _CRT_SECURE_NO_WARNINGS 1
//������֮�͡�
//����һ����������nums��һ������Ŀ��ֵtarget��
//�ڸ��������ҳ���ΪĿ��ֵtarget���������������������ǵ������±ꡣ
//���Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
//���԰�����˳�򷵻ش𰸡�

#include<stdio.h>
#include<stdlib.h>
//#include"uthash.h"

//��1��˫��ѭ��ֱ�ӱ���
int* twoSum1(int* nums, int numsSize, int target, int* returnSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)  //�����������ֵĺ͵���Ŀ��ֵ
            {
                int* ret = (int*)malloc(2 * sizeof(int));  //����һ�������±�ֵ��ָ��
                ret[0] = i;  //���±�ֵ�洢��ָ����
                ret[1] = j;
                *returnSize = 2;  //���س���2
                return ret;  //���ش����±�ֵ��ָ��
            }                //returnSize��ֵ�Ǹ��ⲿ�ӿ��õģ�������֪��������ĳ���
        }
    }
    *returnSize = 0;  //���س���0
    return NULL; // ����Ҳ����������ֵĺ͵���Ŀ��ֵ�����ؿ�ָ��
}

//��2����ϣ��
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
