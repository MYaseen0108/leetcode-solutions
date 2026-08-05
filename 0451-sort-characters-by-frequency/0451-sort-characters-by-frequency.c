#include <stdlib.h>
#include <string.h>

char *frequencySort(char *s)
{
    int n = strlen(s);

    int freq[128] = {0};

    // Count frequencies
    for (int i = 0; i < n; i++)
    {
        freq[(unsigned char)s[i]]++;
    }

    // Bucket array
    char **bucket = (char **)calloc(n + 1, sizeof(char *));

    // Each bucket can hold at most 128 characters
    for (int i = 0; i <= n; i++)
    {
        bucket[i] = (char *)malloc(128);
        bucket[i][0] = '\0';
    }

    // Place characters into buckets
    for (int c = 0; c < 128; c++)
    {
        if (freq[c] > 0)
        {
            int f = freq[c];

            int len = strlen(bucket[f]);
            bucket[f][len] = (char)c;
            bucket[f][len + 1] = '\0';
        }
    }

    char *ans = (char *)malloc(n + 1);

    int idx = 0;

    // Traverse buckets from highest frequency
    for (int f = n; f >= 1; f--)
    {
        for (int j = 0; bucket[f][j] != '\0'; j++)
        {
            for (int k = 0; k < f; k++)
            {
                ans[idx++] = bucket[f][j];
            }
        }
    }

    ans[idx] = '\0';

    // Free buckets
    for (int i = 0; i <= n; i++)
        free(bucket[i]);

    free(bucket);

    return ans;
}