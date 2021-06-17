//https://leetcode.com/problems/longest-palindromic-substring/
// lc 5

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        int m = s.length();
        int n = s1.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (s[i - 1] == s1[j - 1])
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
            if (s[i - 1] == s1[j - 1])
            {
                ans.push_back(s[i - 1]);
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
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