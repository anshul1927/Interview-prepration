// https://www.interviewbit.com/problems/subset-sum-problem/

#include <bits/stdc++.h>
using namespace std;

int Solution::solve(vector<int> &A, int B)
{

    bool dp[B + 1];
    memset(dp, false, sizeof dp);

    dp[0] = true;

    for (auto el : A)
    {
        for (int i = B; i > 0; i--)
        {
            if (el <= i)
            {
                dp[i] = dp[i] || dp[i - el];
            }
        }
    }
    if (dp[B])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}