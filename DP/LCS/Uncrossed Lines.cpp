// https://leetcode.com/problems/uncrossed-lines/
// lc 1035
// same as lcs

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};
int main()
{
    int n;
    cin >> n;
}