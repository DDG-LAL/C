#define _CRT_SECURE_NO_WARNINGS 1
//������֮�͡�
//����һ����������nums��һ������Ŀ��ֵtarget��
//�ڸ��������ҳ���ΪĿ��ֵtarget���������������������ǵ������±ꡣ
//���Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
//���԰�����˳�򷵻ش𰸡�

#include<stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* ret = (int*)malloc(2 * sizeof(int));  //����һ�������±�ֵ��ָ��
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)  //�ҵ��������ֵĺ͵���Ŀ��ֵ
            {
                ret[0] = i;  //���±�ֵ�洢��ָ����
                ret[1] = j;
                *returnSize = 2;  //���ص�ָ�볤��Ӧ����2
                return ret;  //���ش����±�ֵ��ָ��
            }
        }
    }
    return NULL; // ����Ҳ����������ֵĺ͵���Ŀ��ֵ�����ؿ�ָ��
}

int main()
{
    int a[] = { 1, 2, 3, 4 };
    int target = 5;
    int rsize = 0;
    int* r = twoSum(a, 4, 6, &rsize);
    printf("%d %d", r[0], r[1]);
    return 0;
}
