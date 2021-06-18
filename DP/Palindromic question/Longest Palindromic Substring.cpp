//https://leetcode.com/problems/longest-palindromic-substring/
//lc 5

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        int dp[n][n];

        int ans = 0;
        int left = 0;
        int right = 0;

        for (int g = 0; g < n; g++)
        {

            for (int i = 0, j = g; j < n; i++, j++)
            {

                if (g == 0)
                {
                    dp[i][j] = 1;
                    if (ans < g)
                    {
                        ans = g;
                        left = i;
                        right = j;
                    }
                }
                else if (g == 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = 1;
                        if (ans < g)
                        {
                            ans = g;
                            left = i;
                            right = j;
                        }
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
                        if (ans < g)
                        {
                            ans = g;
                            left = i;
                            right = j;
                        }
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
        cout << left << " " << right << " " << ans << endl;

        return s.substr(left, right - left + 1);
    }
};

int main()
{
    int n;
    cin >> n;
}