#include <stdio.h>

/*
int* twoSum(int* nums, int numSize, int target, int* returnSize)
{
    int *result = malloc(2*sizeof(int));
    for(int i = 0; i < numsSize - 1; i++)
    {
        for(int j = 1 + i; j < numsSize - 1; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                *resultSize = 2;
                return result;
            }
        }
    }
    return NULL;
}
*/

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int m = 0;
    int j;
    int *result = malloc(numsSize*sizeof(int));
    for(i = 0; i < numsSize; i++)
    {
        int sum = 0
        int j;
        for(j = 0; j < numsSize;)
        {
            if(nums[i]>nums[j])
            {
                sum++;
                j++;
            }
            else
            {
                j++;
            }
        }
        result[m++] = sum;
        *returnSize = m;
    }
    return result;
}
