#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int start, int end)
{

    int t1 = 0;
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (arr[j] < arr[end])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);

    return i + 1;
}

void quickSort(vector<int> &arr, int start, int end)
{

    if (start >= end)
    {
        return;
    }
    int mid = partition(arr, start, end);

    quickSort(arr, start, mid - 1);
    quickSort(arr, mid + 1, end);
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

    quickSort(arr, 0, n - 1);

    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}