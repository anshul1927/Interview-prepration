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

int isSubsetSum(vector<int> &a, int S)
{
    int sum = 0;
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    if (sum < S || (sum - S) % 2 == 1)
        return 0;
    int target = (sum - S) / 2;

    int dp[target + 1];

    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    for (auto el : a)
    {
        for (int i = target; i >= el; i--)
        {
            dp[i] = dp[i] + dp[i - el];
        }
    }

    return dp[target];
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

    int target;
    cin >> target;

    cout << "Target sum is " << isSubsetSum(a, target) << endl;

    return 0;
}