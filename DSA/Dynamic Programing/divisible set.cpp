// You are given an array of distinct numbers ‘arr’.Your task is to return the largest subset of numbers from ‘arr’, such that any pair of numbers ‘a’ and ‘b’ from the subset satisfies the following : a % b == 0 or b % a == 0.

/*
1 16 7 8 4 => 1 4 8 16

*/

#include <bits/stdc++.h>
using namespace std;
vector<int> divisibleSet(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    vector<int> dp(n, 1), hash(n);
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
    }
    int maxi = 0;
    int maxindex = 0;
    sort(arr.begin(), arr.end());
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] % arr[j] == 0 and dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            maxindex = i;
        }
    }
    vector<int> ans;
    while (hash[maxindex] != maxindex)
    {
        ans.push_back(arr[maxindex]);
        maxindex = hash[maxindex];
    }
    ans.push_back(arr[maxindex]);
    reverse(ans.begin(), ans.end());
    return ans;
}