

#include <bits/stdc++.h>
using namespace std;

//dp approach

int maxSubarraySum(vector<int> a, int n)
{
    int maxSum = a[0];
    int currSum = a[0];

    for (int i = 0; i < n; i++)
    {
        currSum = max(a[i], currSum + a[i]);
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    int start = 0;
    int end = 0;
    int s = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int maxSum = 0;
    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += a[i];
        if (maxSum < currSum)
        {
            maxSum = currSum;
            start = s;
            end = i;
        }

        if (currSum < 0)
        {
            currSum = 0;
            s = i + 1;
        }
    }
    cout << " start " << start << " end " << end << endl;

    cout << maxSubarraySum(a, n) << endl;
    return 0;
}