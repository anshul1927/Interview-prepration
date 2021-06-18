//https://www.interviewbit.com/problems/longest-palindromic-subsequence/

#include <bits/stdc++.h>
using namespace std;

// int solve(string A)
// {
//     string B = A;
//     reverse(B.begin(), B.end());

//     vector<vector<int>> dp(A.length() + 1, vector<int>(B.length() + 1, -1));

//     for (int i = 0; i <= A.length(); i++)
//     {
//         for (int j = 0; j <= B.length(); j++)
//         {
//             if (i == 0 || j == 0)
//             {
//                 dp[i][j] = 0;
//             }
//             else if (A[i - 1] == B[j - 1])
//             {
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//             }
//             else
//             {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//     }

//     return dp[A.length()][B.length()];
// }

int solve(vector<int> A)
{
    vector<int> B = A;
    reverse(B.begin(), B.end());

    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, -1));

    for (int i = 0; i <= A.size(); i++)
    {
        for (int j = 0; j <= B.size(); j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[A.size()][B.size()];
}

int main()
{

    int n;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;

        vector<int> a(k);
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }

        if (solve(a) >= 3)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
