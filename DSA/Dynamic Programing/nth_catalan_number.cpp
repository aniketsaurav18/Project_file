/*
Given a number N. The task is to find the Nth catalan number.
The first few Catalan numbers for N = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
Note: Positions start from 0 as shown above.


formula => C(n+1) = [sigma from 0 to n] C(i)*c(n-i)


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the nth catalan number.
    cpp_int f(int n, vector<cpp_int> &dp)
    {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        cpp_int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += f(i, dp) * f(n - i - 1, dp);
        }
        return dp[n] = ans;
    }
    cpp_int findCatalan(int n)
    {
        // code here
        vector<cpp_int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            cpp_int ans = 0;
            for (int j = 0; j < i; j++)
            {
                ans += dp[j] * dp[i - j - 1];
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};