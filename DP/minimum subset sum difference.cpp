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

int isSubsetSum(vector<int> &a, int n, int sum)
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

    int ans = INT_MAX;

    for (int i = 0; i <= sum / 2; i++)
    {
        int first = i;
        int second = sum - i;
        if (dp[i] && ans > abs(first - second))
        {
            ans = abs(first - second);
        }
    }

    return ans;
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

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    cout << "Minimum subset sum difference is " << isSubsetSum(a, n, sum) << endl;

    return 0;
}