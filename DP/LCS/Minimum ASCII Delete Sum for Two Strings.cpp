//https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
// lc712

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {

        int m = s1.length();
        int n = s2.length();

        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof dp);
        int prefix1[m], prefix2[n];
        prefix1[0] = (int)s1[0];
        for (int i = 1; i < m; i++)
        {
            prefix1[i] = prefix1[i - 1] + (int)s1[i];
        }
        prefix2[0] = (int)s2[0];
        for (int i = 1; i < n; i++)
        {
            prefix2[i] = prefix2[i - 1] + (int)s2[i];
        }

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {

                if (i == 0 && j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (i == 0)
                {
                    dp[i][j] = prefix2[j - 1];
                }
                else if (j == 0)
                {
                    dp[i][j] = prefix1[i - 1];
                }
                else if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j] + (int)(s1[i - 1]), dp[i][j - 1] + (int)(s2[j - 1]));
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