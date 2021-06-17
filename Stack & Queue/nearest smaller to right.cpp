

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    stack<int> s;
    vector<int> ans(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            ans[i] = -1;
        }
        else if (!s.empty() && s.top() < nums[i])
        {
            ans[i] = s.top();
        }
        else if (!s.empty() && s.top() >= nums[i])
        {
            while (!s.empty() && s.top() >= nums[i])
                s.pop();
            if (s.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = s.top();
            }
        }
        s.push(nums[i]);
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}