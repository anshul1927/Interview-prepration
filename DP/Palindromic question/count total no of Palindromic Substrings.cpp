// https://leetcode.com/problems/palindromic-substrings/
// lc 647

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();
        int dp[n][n];

        int ans = 0;
        for (int g = 0; g < n; g++)
        {

            for (int i = 0, j = g; j < n; i++, j++)
            {

                if (g == 0)
                {
                    dp[i][j] = 1;
                    ans++;
                }
                else if (g == 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = 1;
                        ans++;
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }
                else if (dp[i + 1][j - 1] == 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = 1;
                        ans++;
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
}