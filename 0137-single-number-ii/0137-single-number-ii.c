//Better but not optimal 
//For optimal prefer my CPP code

int compare(const void *a,const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    return ((x>y)-(x<y));
}

int singleNumber(int* nums, int numsSize) 
{
    qsort(nums,numsSize,sizeof(int),compare);

    for(int i=1; i<numsSize; i=i+3)
    {
        if(nums[i] != nums[i-1])
        {
            return nums[i-1];
        }
    }
    return nums[numsSize-1];
    
}