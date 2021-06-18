

#include <bits/stdc++.h>
using namespace std;

int MCMrecursive(int arr[], int i, int j)
{
    if (i == j)
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        ans = min(ans, MCMrecursive(arr, i, k) + MCMrecursive(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j]);
    }

    return ans;
}

int MCMmemo(int arr[], int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;

    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], MCMmemo(arr, i, k, dp) + MCMmemo(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j]);
    }
    return dp[i][j];
}

int MCMBU(int arr[], int n)
{
    int dp[n - 1][n - 1];

    for (int g = 0; g < n - 1; g++)
    {
        for (int i = 0, j = g; j < n - 1; j++, i++)
        {
            if (g == 0)
            {
                dp[i][j] = 0;
            }
            else if (g == 1)
            {
                dp[i][j] = arr[i] * arr[j] * arr[j + 1];
            }
            else
            {
                int m = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int lc = dp[i][k];
                    int rc = dp[k + 1][j];
                    int cv = arr[i] * arr[k + 1] * arr[j + 1];

                    int tc = lc + rc + cv;
                    m = min(m, tc);
                }
                dp[i][j] = m;
            }
        }
    }

    return dp[0][n - 2];
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << MCMrecursive(arr, 1, n - 1);

    cout << endl
         << MCMmemo(arr, 1, n - 1, dp);

    cout << endl
         << MCMBU(arr, n);
    return 0;
}