/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive fences have the same colors. Since the answer can be large return it modulo 10^9 + 7.



link = > https : // www.geeksforgeeks.org/painting-fence-algorithm/

*/
class Solution
{
public:
    int mod = 1e9 + 7;
    long long f(int n, int k, vector<long long> &dp)
    {

        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return k;
        }
        if (n == 2)
        {
            return (k + k * (k - 1)) % mod;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int same = (k - 1) * f(n - 2, k, dp) % mod;
        int diff = (k - 1) * f(n - 1, k, dp) % mod;

        return dp[n] = (same + diff) % mod;
    }
    long long countWays(int n, int k)
    {
        // code here
        vector<long long> dp(n + 1, 0);
        dp[1] = k;
        dp[2] = (k + k * (k - 1)) % mod;
        for (int i = 3; i <= n; i++)
        {
            int same = ((k - 1) * dp[i - 2]) % mod;
            int diff = ((k - 1) * dp[i - 1]) % mod;

            dp[i] = (same + diff) % mod;
        }
        return dp[n];
    }
};