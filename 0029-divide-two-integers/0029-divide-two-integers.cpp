class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        if (dividend == divisor)
            return 1;

        bool negative = (dividend < 0) ^ (divisor < 0);

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long ans = 0;

        while (n >= d)
        {
            int cnt = 0;

            while (n >= (d << (cnt + 1)))
            {
                cnt++;
            }

            ans += (1LL << cnt);
            n -= (d << cnt);
        }

        if (negative)
            ans = -ans;

        if (ans > INT_MAX)
            return INT_MAX;

        if (ans < INT_MIN)
            return INT_MIN;

        return (int)ans;
    }
};