/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int nums[], int n, int target, int* retsize) 
{
    int * ret = (int *)malloc(2*sizeof(int));
    *retsize = 2;

   for(int i=0; i<n; i++)
   {
    for(int j=i+1; j<n; j++)
    {
        if(nums[i] + nums[j] == target)
        {
            ret[0]=i;
            ret[1]=j;
            return ret;
        }
        
    }
   }  
   ret[0]=0;
   ret[1]=1;
   return ret;  
}