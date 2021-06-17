//https://www.interviewbit.com/problems/minimum-difference-subsets/

#include <bits/stdc++.h>
using namespace std;

int Solution::solve(vector<int> &A)
{

    int sum = 0;
    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }

    int dp[sum + 1];

    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    for (auto el : A)
    {
        for (int i = sum; i > 0; i--)
        {
            if (el <= i)
            {
                dp[i] += dp[i - el];
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