#include <string.h>

int lengthOfLongestSubstring(char* s) 
{
    int n = strlen(s);

    int index[128];
    for(int i=0; i<128; i++)
    {
        index[i]=-1;
    }
    int max =0;

    int start =0;

    for(int end =0; end < n; end++)
    {
        char ch = s[end];

        if(index[ch] >= start)
        {
            start = index[ch]+1;
        }

        index[ch] = end;

        int len = end - start + 1;

        if(len > max)
        {
            max = len;
        }
    }

    return max;
}