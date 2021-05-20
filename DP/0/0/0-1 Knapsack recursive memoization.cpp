#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int knapsack(int wt[], int profit[], int w, int n)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }

    if (dp[w][n] != -1)
        return dp[w][n];
    int result = 0; //
    if (wt[n] > w)
    {
        result = knapsack(wt, profit, w, n - 1);
    }
    else
    {
        result = max(knapsack(wt, profit, (w - wt[n]), (n - 1)) + profit[n], knapsack(wt, profit, w, n - 1));
    }

    return dp[w][n] = result;
}
int main()
{
    int w, n;
    cin >> w >> n;
    int wt[n + 1];
    int profit[n + 1];

    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> profit[i];
    }
    int ans = knapsack(wt, profit, w, n);
    cout << ans << endl;
    return 0;
}