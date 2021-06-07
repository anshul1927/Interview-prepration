
/*
    two element form a inversion if a[i]>a[j] and i<j;
*/

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int start, int end)
{
    int i = start;
    int mid = (start + end) >> 1;
    int j = mid + 1;
    int inversion = 0;
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
            inversion += mid - i + 1; // 0 2 5 and 1 3 now 2 is greater than 1 so that mean it will form a inversion but after 2 whatever element present in that part also form inversion with 1.
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
    cout << "start " << start << " end " << end << " " << inversion << endl;
    return inversion;
}

int inversion_count(vector<int> &arr, int start, int end)
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

    int s = 0;
    int e = n - 1;
    int inversion = inversion_count(arr, s, e);

    cout << " total inversion " << inversion << endl;
    return 0;
}