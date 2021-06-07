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

int quickSort(vector<int> &arr, int start, int end, int k)
{

    int mid = partition(arr, start, end);

    if (mid == k)
    {
        return arr[mid];
    }
    if (mid > k)
    {
        return quickSort(arr, start, mid - 1, k);
    }
    else
    {
        return quickSort(arr, mid + 1, end, k);
    }
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
    int k;
    cin >> k;

    cout << quickSort(arr, 0, n - 1, k);
    return 0;
}