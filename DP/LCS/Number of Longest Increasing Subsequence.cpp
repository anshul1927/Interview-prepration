//https://leetcode.com/problems/number-of-longest-increasing-subsequence/
// lc 673

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {

        vector<int> dp(nums.size(), 1), cnt(nums.size(), 1);

        int maxi = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                {
                    dp[i] = 1 + dp[j];
                    cnt[i] = cnt[j];
                }
                else if (dp[j] + 1 == dp[i])
                {
                    cnt[i] += cnt[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        //         for(auto it: dp){
        //             cout<<it<<" ";
        //         }
        //         cout<<endl;

        //         for(auto it: cnt){
        //             cout<<it<<" ";
        //         }
        //         cout<<endl;

        int ans = 0;

        for (int i = 0; i < dp.size(); i++)
        {
            if (dp[i] == maxi)
                ans += cnt[i];
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
}