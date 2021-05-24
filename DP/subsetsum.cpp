#include <bits/stdc++.h>
using namespace std;

/*bool isSubsetSum(int a[], int n, int sum)
{
    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 0; i <= sum; i++)
    {
        dp[0][i] = false; //
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < a[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }

            if (j >= a[i - 1])
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
            }
        }
    }

    return dp[n][sum];
}*/

// 1-D dp approach

bool isSubsetSum(vector<int> &a, int n, int sum)
{
    bool dp[sum + 1];

    memset(dp, false, sizeof dp);
    dp[0] = true;

    for (auto el : a)
    {
        for (int i = sum; i > 0; i--)
        {
            if (el <= i)
            {
                dp[i] = dp[i] || dp[i - el];
            }
        }
    }
    return dp[sum];
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int sum;
    cin >> sum;

    if (isSubsetSum(a, n, sum))
    {
        cout << "Found a subset with given sum";
    }
    else
    {
        cout << "No subset with given sum";
    }

    return 0;
}