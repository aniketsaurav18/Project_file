/*
You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below.

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.


Return the minimum number of moves that you need to determine with certainty what the value of f is.

*/

class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int f(int e, int fl, vector<vector<int>> &dp)
    {
        if (e == 1)
        {
            return fl;
        }
        if (fl <= 1)
        {
            return fl;
        }
        if (dp[e][fl] != -1)
        {
            return dp[e][fl];
        }
        int ans = INT_MAX;
        for (int i = 1; i <= fl; i++)
        {
            ans = min(ans, 1 + max(f(e - 1, i - 1, dp), f(e, fl - i, dp)));
        }
        return dp[e][fl] = ans;
    }
    int eggDrop(int n, int k)
    {
        // your code here
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= k; i++)
        {
            dp[1][i] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            dp[i][1] = 1;
        }
        for (int e = 2; e <= n; e++)
        {
            for (int fl = 2; fl <= k; fl++)
            {
                int ans = INT_MAX;
                for (int i = 1; i <= fl; i++)
                {
                    ans = min(ans, 1 + max(dp[e - 1][i - 1], dp[e][fl - i]));
                }
                dp[e][fl] = ans;
            }
        }
        return dp[n][k];
    }
};