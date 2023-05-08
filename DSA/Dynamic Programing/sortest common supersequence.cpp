/*
Given two strings, ‘A’ and ‘B’.Return the shortest supersequence string ‘S’, containing both ‘A’ and ‘B’ as its subsequences.If there are multiple answers, return any of them.Note : A string 's' is a subsequence of string 't' if deleting some number of characters from 't'(possibly 0)results in the string 's'.

Suppose ‘A’ = “brute”, and ‘B’ = “groot”

The shortest supersequence will be “bgruoote”. As shown below, it contains both ‘A’ and ‘B’ as subsequences.

A   A A     A A
b g r u o o t e
  B B   B B B

It can be proved that the length of supersequence for this input cannot be less than 8. So the output will be bgruoote.


*/

#include <bits/stdc++.h>
using namespace std;

string shortestSupersequence(string a, string b)
{
    // Write your code here.
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // generate the count table of longest common subsequence using DP
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                continue;
            }
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int i = n, j = m;
    string ans = "";
    // generate the string using backtracking of the table
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            ans += a[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += a[i - 1];
                i--;
            }
            else
            {
                ans += b[j - 1];
                j--;
            }
        }
    }
    if (i != 0)
    {
        while (i != 0)
        {
            ans += a[i - 1];
            i--;
        }
    }
    else
    {
        while (j != 0)
        {
            ans += b[j - 1];
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}