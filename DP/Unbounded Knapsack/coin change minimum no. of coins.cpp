#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> coins, int amount)
{
    if (amount == 0)
    {
        return 0;
    }

    int dp[amount + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= amount; i++)
    {
        dp[i] = 1e5;
        for (auto el : coins)
        {
            if (el <= i)
            {
                dp[i] = min(dp[i], 1 + dp[i - el]);
            }
        }
    }
    return dp[amount] > 1e4 ? -1 : dp[amount];
}

int main()
{
    int n;
    cin >> n;
    vector<int> coins;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        coins.push_back(temp); //
    }

    int amount;
    cin >> amount;

    cout << "minimum no of coins required " << coinChange(coins, amount) << endl;
    return 0;
}