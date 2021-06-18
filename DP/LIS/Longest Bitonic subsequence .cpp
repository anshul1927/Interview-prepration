// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int LongestBitonicSequence(vector<int> nums)
    {
        // code here
        int n = nums.size();
        // longest increasing from left
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        // for(auto it: dp){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // longest decreasing from right
        vector<int> dp1(n, 1);
        int ans = dp[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (nums[j] < nums[i] && dp1[i] < dp1[j] + 1)
                {
                    dp1[i] = dp1[j] + 1;
                }
            }
            dp[i] += dp1[i] - 1;

            ans = max(ans, dp[i]);
        }

        // for(auto it: dp1){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.LongestBitonicSequence(nums);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends