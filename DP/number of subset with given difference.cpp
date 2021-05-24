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

int isSubsetSum(vector<int> &a, int n, int sum, int diff)
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

    int ans = 0;

    for (int i = 0; i <= sum / 2; i++)
    {
        int first = i;
        int second = sum - i;
        if (dp[i] && (diff == abs(first - second)))
        {
            ans++;
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

    int diff;
    cin >> diff;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    cout << "number of subset with given difference " << isSubsetSum(a, n, sum, diff) << endl;

    return 0;
}