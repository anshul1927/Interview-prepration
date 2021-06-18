

#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> &arr, int n)
{
    vector<int> dp(n, 1);
    //    memset(dp, 1, sizeof dp);

    int res = dp[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] <= dp[j])
            {
                dp[i] = 1 + dp[j];
                res = max(res, dp[i]);
            }
        }
    }
    return res;
}

void LISsequence(vector<int> &arr, int n)
{
    vector<int> dp(n, 1);
    //    memset(dp, 1, sizeof dp);

    int res = dp[0];
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] <= dp[j])
            {
                dp[i] = 1 + dp[j];
                if (res < dp[i])
                {
                    idx = i;
                    res = dp[i];
                }
                //res = max(res, dp[i]);
            }
        }
    }

    cout << res << idx << endl;

    vector<int> ans;
    ans.push_back(arr[idx]);

    idx--;
    while (res > 1)
    {
        if (dp[idx] == res - 1)
        {
            res--;
            // cout << idx << " " << res << " " << arr[idx] << endl;
            ans.push_back(arr[idx]);
            idx--;
        }
        else
        {
            idx--;
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // length of LIST
    cout << LIS(arr, n);

    // LIS sequence
    LISsequence(arr, n);
    return 0;
}