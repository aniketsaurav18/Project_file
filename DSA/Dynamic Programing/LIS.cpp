/*


Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.


*/

class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int lb(vector<int> v, int target)
    {
        int l = 0, r = v.size() - 1, mid = 0;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (v[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return r;
    }
    int longestSubsequence(int n, int a[])
    {
        // your code here
        vector<int> ans;
        ans.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            if (a[i] > ans.back())
            {
                ans.push_back(a[i]);
            }
            else
            {
                int ind = lb(ans, a[i]); // instead of lb we can use inbuit lower_bound fun
                ans[ind] = a[i];
            }
        }
        return ans.size();
    }
};