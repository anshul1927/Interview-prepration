

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

    int k;
    cin >> k;

    deque<int> dq(k);
    int i = 0;
    for (i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    cout << dq.size() << endl;
    for (i = k; i < n; i++)
    {
        cout << arr[dq.front()] << " ";
        while (!dq.empty() and dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << dq.front();
    return 0;
}