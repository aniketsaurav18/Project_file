/* A thief is robbing a store and can carry a maximal weight of W into his knapsack.There are N items and the ith item weighs wi and is of value vi.Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.


4 (number of items(n))
1 2 4 5 (weight)
5 4 8 6 (value)
5  (maxWeight)
*/

/*
(problem link)
https:// www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
*/
#include <bits/stdc++.h>
using namespace std;

// recursive function with dp(memoiation)
int solve(int i, vector<int> weight, vector<int> value, int n, int currweight, vector<vector<int>> &dp)
{
    if (i == n - 1)
    {
        if (weight[i] <= currweight)
        {
            return value[i];
        }
        else
        {
            return 0;
        }
    }
    if (dp[i][currweight] != -1)
    {
        return dp[i][currweight];
    }
    int notpick = 0 + solve(i + 1, weight, value, n, currweight, dp);
    int pick = INT_MIN;
    if (weight[i] <= currweight)
    {
        pick = value[i] + solve(i + 1, weight, value, n, currweight - weight[i], dp);
    }
    return dp[i][currweight] = max(pick, notpick);
}

// solution with tabulation+ space optimization
//  TC - O(maxWeight of knapsack * n)
//  SC - O(maxWeight)
//  n -> number of element
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> dp(maxWeight + 1, 0);
    // dp[i] signifies that what is the maximum value thief can get with i capacity of knapsack
    for (int i = 0; i <= maxWeight; i++)
    {
        if (i >= weight[0])
        {
            dp[i] = value[0];
        }
    }
    for (int i = 1; i < n; i++)
    {

        for (int j = maxWeight; j >= 0; j--)
        {
            int notpick = dp[j];
            int pick = INT_MIN;
            if (weight[i] <= j)
            {
                pick = value[i] + dp[j - weight[i]];
            }
            dp[j] = max(pick, notpick);
        }
    }
    return dp[maxWeight];
}