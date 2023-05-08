#include <bits/stdc++.h>
using namespace std;

/*
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.


*/

class Solution
{
public:
    // recursion + memoisation
    long long int f(int i, int s[], int m, int n, vector<vector<long long int>> &dp)
    {
        if (i < 0 || n < 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }
        if (i == 0)
        {
            if (n % s[i] == 0)
            {
                return 1;
            }
            return 0;
        }
        if (dp[i][n] != -1)
        {
            return dp[i][n];
        }
        long long int pick = f(i, s, m, n - s[i], dp);
        long long int notpick = f(i - 1, s, m, n, dp);
        return dp[i][n] = pick + notpick;
    }

    // tabulation
    long long int count(int s[], int m, int n)
    {

        // code here.
        vector<vector<long long int>> dp(m, vector<long long int>(n + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            if (i % s[0] == 0)
            {
                dp[0][i] = 1;
            }
        }
        for (int j = 0; j < m; j++)
        {
            dp[j][0] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                long long int pick = 0;
                if (j - s[i] >= 0)
                {
                    pick = dp[i][j - s[i]];
                }

                long long int notpick = dp[i - 1][j];
                dp[i][j] = pick + notpick;
            }
        }
        return dp[m - 1][n];
    }
};

int main()
{

    return 0;
}