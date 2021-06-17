#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w, n;
    cin >> w >> n;
    int wt[n];
    int profit[n];

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }

    int dp[w + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i <= n; i++)
    {
        for (int j = w; j >= 0; j--)
        {
            if (j >= wt[i])
                dp[j] = max(dp[j], profit[i] + dp[j - wt[i]]);
        }
    }

    cout << dp[w] << endl;
    return 0;
}