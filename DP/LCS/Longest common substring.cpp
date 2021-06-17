

#include <bits/stdc++.h>
using namespace std;

// recursive approach with memoization

int LCSdp(string s, string s1, int i, int j, vector<vector<int>> &dp)
{
    if (i == s.length() || j == s1.length())
    {
        return 0;
    }

    int res = INT_MIN;
    if (dp[i][j] == -1)
    {
        if (s[i] == s[j])
        {
            dp[i][j] = 1 + LCSdp(s, s1, i + 1, j + 1, dp);
            res = max(dp[i][j], res);
        }

        else
        {
            dp[i][j] = 0;
        }
    }
    return res;
}

// bottom up
int LCSbu(string s, string s1)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(s1.length() + 1, -1));

    int res = INT_MIN;
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
                res = max(res, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
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
    return res;
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
    cout << "##5";
    vector<vector<int>> dp(2, vector<int>(s2.length(), -1));
    cout << "##4";
    int bi;
    int res = INT_MIN;
    cout << "##3";
    for (int i = 0; i <= s1.length(); i++)
    {

        cout << "##";
        bi = i & 1;
        for (int j = 0; j <= s2.length(); j++)
        {

            cout << "##1";

            if (i == 0 || j == 0)
            {
                dp[bi][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[bi][j] = 1 + dp[1 - bi][j - 1]; // 1 - bi at a time bi can be 0 or 1 so i need to take complement of bi;
                res = max(res, dp[bi][j]);
            }
            else
            {
                dp[bi][j] = 0;
            }
        }
    }
    cout << "##2";
    return res;
}

int main()
{

    string s, s1;
    cout << "#8";
    cin >> s >> s1;

    // vector<vector<int>> dp(s.length(), vector<int>(s1.length(), -1));
    cout << "##7";
    cout << LCSo(s, s1);
    return 0;
}