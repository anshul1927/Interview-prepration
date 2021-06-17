//https://leetcode.com/problems/shortest-common-supersequence/
// lc 1092

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string s1, string s2)
    {

        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {

                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string ans = "";

        int i = m;
        int j = n;
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans.push_back(s1[i - 1]);
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans.push_back(s1[i - 1]);
                i--;
            }
            else
            {
                ans.push_back(s2[j - 1]);
                j--;
            }
        }

        while (i > 0)
        {
            ans.push_back(s1[i - 1]);
            i--;
        }
        while (j > 0)
        {
            ans.push_back(s2[j - 1]);
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
}