// https://www.interviewbit.com/problems/black-shapes/

/* 
OOOXOOO
OOXXOXO
OXOOOXO
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<string> &A)
{
    if (i < 0 or i >= A.size() or j < 0 or j >= A[0].size() or A[i][j] != 'X')
    {
        return;
    }

    A[i][j] = '#';

    dfs(i + 1, j, A);
    dfs(i, j + 1, A);
    dfs(i - 1, j, A);
    dfs(i, j - 1, A);
}

int Solution::black(vector<string> &A)
{

    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            if (A[i][j] == 'X')
            {
                dfs(i, j, A);
                ans++;
            }
        }
    }

    return ans;
}
