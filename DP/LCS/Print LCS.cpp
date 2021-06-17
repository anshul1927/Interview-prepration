

#include <bits/stdc++.h>
using namespace std;

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

    string ans = "";
    int i = s.length();
    int j = s1.length();
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == s1[j - 1])
        {
            ans += s[i - 1];
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
    cout << ans << endl;
    return dp[s.length()][s1.length()];
}

int main()
{

    string s, s1;
    cin >> s >> s1;

    vector<vector<int>> dp(s.length(), vector<int>(s1.length(), -1));
    cout << LCSbu(s, s1);
    return 0;
}