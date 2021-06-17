

#include <bits/stdc++.h>
using namespace std;

// recursive approach
int LCS(string s, string s1, int i, int j)
{
    if (i == s.length() || j == s1.length())
    {
        return 0;
    }

    if (s[i] == s[j])
    {
        return 1 + LCS(s, s1, i + 1, j + 1);
    }

    int c1 = LCS(s, s1, i + 1, j);
    int c2 = LCS(s, s1, i, j + 1);

    return max(c1, c2);
}

// recursive approach with memoization

int LCSdp(string s, string s1, int i, int j, vector<vector<int>> &dp)
{
    if (i == s.length() || j == s1.length())
    {
        return 0;
    }

    if (dp[i][j] == -1)
    {
        if (s[i] == s[j])
        {
            dp[i][j] = 1 + LCSdp(s, s1, i + 1, j + 1, dp);
        }

        else
        {
            int c1 = LCSdp(s, s1, i + 1, j, dp);
            int c2 = LCSdp(s, s1, i, j + 1, dp);

            dp[i][j] = max(c1, c2);
        }
    }
    return dp[i][j];
}

// bottom up
int LCSbu(string s, string s1)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(s1.length() + 1, -1));

    for (int i = 0; i <= s.length(); i++)
    {

        for (int j = 0; j <= s1.length(); j++)
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

    for (auto it : dp)
    {
        for (auto el : it)
        {
            cout << el << " ";
        }
        cout << endl;
    }
    return dp[s.length()][s1.length()];
}

// 1-D DP solution
/*
0 0 0 0 0 
0 0 0 0 1 
0 0 1 1 1 
0 0 1 2 2 
0 1 1 2 2 
0 1 1 2 3
*/
// at a time we can only use 2 row if i need to calculate for i,j row then i need only i-1 and j-1 row so
// we can reduce space by use of only dp[2][s1.length()];

// optimized approach

int LCSo(string s1, string s2)
{

    vector<vector<int>> dp(2, vector<int>(s2.length(), -1));

    int bi;
    for (int i = 0; i <= s1.length(); i++)
    {

        bi = i & 1;
        for (int j = 0; j <= s2.length(); j++)
        {

            if (i == 0 || j == 0)
            {
                dp[bi][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[bi][j] = 1 + dp[1 - bi][j - 1]; // 1 - bi at a time bi can be 0 or 1 so i need to take complement of bi;
            }
            else
            {
                dp[bi][j] = max(dp[1 - bi][j], dp[bi][j - 1]);
            }
        }
    }

    return dp[bi][s2.length()];
}

int main()
{

    string s, s1;
    cin >> s >> s1;

    vector<vector<int>> dp(s.length(), vector<int>(s1.length(), -1));
    cout << LCS(s, s1);
    return 0;
}