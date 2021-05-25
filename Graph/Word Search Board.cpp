// https://www.interviewbit.com/problems/word-search-board/

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int row, int col, vector<string> &A, string B, int length)
{

    if (length == B.size())
    {
        return 1;
    }

    if (row < 0 or row >= A.size() or col < 0 or col >= A[0].size() or A[row][col] != B[length])
    {
        return false;
    }
    for (int i = 0; i < 4; i++)
    {
        if (dfs(row + dx[i], col + dy[i], A, B, length + 1))
            return 1;
    }

    return 0;
}

int Solution::exist(vector<string> &A, string B)
{

    char root = B[0];

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            if (dfs(i, j, A, B, 0))
                return 1;
        }
    }

    return 0;
}
