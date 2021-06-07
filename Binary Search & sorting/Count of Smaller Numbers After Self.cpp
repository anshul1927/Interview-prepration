//https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// lc315
// do it again

#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

int merge(vector<pair<int, int>> &arr, int start, int end)
{
    int i = start;
    int mid = (start + end) >> 1;
    int j = mid + 1;
    int inversion = 0;
    vector<pair<int, int>> temp;

    while (i <= mid && j <= end)
    {
        if (arr[i].second <= arr[j].second)
        {
            temp.push_back({i, arr[i].second});
            i++;
        }
        else
        {

            for (int k = i; k <= mid; k++)
            {
                ans[arr[k].first]++;
            }

            temp.push_back({j, arr[j].second});
            inversion += mid - i + 1; // 0 2 5 and 1 3 now 2 is greater than 1 so that mean it will form a inversion but after 2 whatever element present in that part also form inversion with 1.
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back({i, arr[i].second});
        i++;
    }

    while (j <= end)
    {
        temp.push_back({j, arr[j].second});
        j++;
    }
    int k = 0;
    for (int idx = start; idx <= end; idx++)
    {
        arr[idx] = temp[k];
        k++;
    }
    // cout << "start " << start << " end " << end << " " << inversion << endl;
    return inversion;
}

int inversion_count(vector<pair<int, int>> &arr, int start, int end)
{
    // base case
    if (start >= end)
    {
        return 0;
    }
    int mid = (start + end) >> 1;
    int c1 = inversion_count(arr, start, mid);
    int c2 = inversion_count(arr, mid + 1, end);
    return c1 + c2 + merge(arr, start, end);
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

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = {i, arr[i]};
    }
    ans = vector<int>(n, 0);
    // count.resize(n, 0);
    int s = 0;
    int e = n - 1;
    int inversion = inversion_count(a, s, e);

    cout << " total inversion " << inversion << endl;

    for (auto it : a)
    {
        cout << it.first << " " << it.second << endl;
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}