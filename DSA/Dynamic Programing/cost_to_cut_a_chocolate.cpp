/*

You are given chocolate of ‘N’ length.The chocolate is labeled from 0 to ‘N’.You are also given an array ‘CUTS’ of size ‘C’, denoting the positions at which you can do a cut.The order of cuts can be changed.The cost of one cut is the length of the chocolate to be cut.Therefore, the total cost is the sum of all the cuts.Print the minimum cost to cut the chocolate.



*/

// recursive + memoization approach

#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mini = 1e9;
    for (int k = i; k <= j; k++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + f(i, k - 1, cuts, dp) + f(k + 1, j, cuts, dp);
        // cuts[j+1]- cuts[i - 1] signifies the length of the present sequence.

        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

int cost(int n, int c, vector<int> &cuts)
{
    // Write your code here.
    sort(cuts.begin(), cuts.end());
    vector<int> newcut;
    newcut.push_back(0);
    for (auto it : cuts)
    {
        newcut.push_back(it);
    }
    newcut.push_back(n);
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));
    return f(1, newcut.size() - 2, newcut, dp);
}

// tabulation approach