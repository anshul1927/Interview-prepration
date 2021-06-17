

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> dp(n, 1);

    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++)
    {
        if (!s.empty() && s.top().second <= arr[i])
        {
            cout << "i is " << i << endl;
            while (!s.empty() && s.top().second <= arr[i])
            {
                dp[i] += dp[s.top().first];
                s.pop();
            }
        }
        // cout << i << " " << arr[i] << endl;
        s.push({i, arr[i]});
        cout << s.top().first << " " << s.top().second << endl;
    }

    for (auto it : dp)
    {
        cout << it << " ";
    }
    return 0;
}