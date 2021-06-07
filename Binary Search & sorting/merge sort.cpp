
/*
    1. Divide the array into 2 parts.
    2. then recursvely sort left part and right part.
    3. merge them into a single sorted array.
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int start, int end)
{
    int i = start;
    int mid = (start + end) >> 1;
    int j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    int k = 0;
    for (int idx = start; idx <= end; idx++)
    {
        arr[idx] = temp[k];
        k++;
    }
    return;
}

void mergeSort(vector<int> &arr, int start, int end)
{
    // base case
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) >> 1;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    return merge(arr, start, end);
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

    int s = 0;
    int e = n - 1;
    mergeSort(arr, s, e);
    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}