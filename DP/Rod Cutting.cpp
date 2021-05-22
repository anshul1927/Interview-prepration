#include <bits/stdc++.h>
using namespace std;

int rodCutting(int price[], int n)
{
    int dp[n + 1];

    dp[0] = 0;
    dp[1] = price[0];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = price[i - 1];
        int li = 1;
        int ri = i - 1;
        while (li <= ri)
        {

            if ((dp[li] + dp[ri]) > dp[i])
            {
                dp[i] = dp[li] + dp[ri];
            }
            li++;
            ri--;
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    int price[n];
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    cout << rodCutting(price, n);
    return 0; //
}