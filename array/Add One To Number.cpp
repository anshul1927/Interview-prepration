#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::plusOne(vector<int> &A)
{

    int i;
    if (A.size() != 1)
    {
        for (i = 0; i < A.size(); i++)
        {
            if (A[i] != 0)
            {
                break;
            }
        }
    }

    A.erase(A.begin(), A.begin() + i);

    int n = A.size();

    if (A[n - 1] >= 0 && A[n - 1] <= 8)
    {
        A[n - 1] = A[n - 1] + 1;
    }
    else
    {
        A[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if (A[i] >= 0 && A[i] <= 8)
            {
                A[i] = A[i] + 1;
                break;
            }
            else
            {
                A[i] = 0;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] != 0)
        {
            break;
        }
        cnt++;
    }

    if (cnt == n)
    {
        A.push_back(0);
        A[0] = 1;
    }

    return A;
}
