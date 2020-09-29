#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize)
{
    for(int i=0 ; i<numsSize ; i++)
    {
        if(nums[i] > 0)
        {
            if (nums[i] < (numsSize+1) && (i+1) != nums[i])
            {
                int tmp = nums[i] ;
                if(nums[i] == nums[tmp-1])  nums[i] = 0 ;
                else
                {
                    nums[i] = nums[tmp-1] ;
                    nums[tmp-1] = tmp ;
                    i-- ;
                }
            }
            else if (nums[i] > numsSize) nums[i] = 0 ;
        }
        else nums[i] = 0 ;
    }

    for(int i=0 ; i<numsSize ; i++)
    {
        if(nums[i] == 0)    return i+1 ;
    }
    return numsSize+1 ;
}

int main()
{
    int n[] = {1, 1};

    printf("%d\n", firstMissingPositive(n, 2)) ;
    return 0 ;
}
