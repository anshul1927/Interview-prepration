// https://www.interviewbit.com/problems/water-flow/
// https://leetcode.com/problems/pacific-atlantic-water-flow/
// lc417

#include <bits/stdc++.h>
using namespace std;

int n, m;
void dfs(int i, int j, vector<vector<int>> &A, vector<vector<int>> &b) // b is the visited array
{
    if (b[i][j] == 0)
        b[i][j] = 1;
    if (i > 0 && A[i - 1][j] >= A[i][j] && b[i - 1][j] == 0)
        dfs(i - 1, j, A, b);
    if (j > 0 && A[i][j - 1] >= A[i][j] && b[i][j - 1] == 0)
        dfs(i, j - 1, A, b);
    if (j < m - 1 && A[i][j + 1] >= A[i][j] && b[i][j + 1] == 0)
        dfs(i, j + 1, A, b);
    if (i < n - 1 && A[i + 1][j] >= A[i][j] && b[i + 1][j] == 0)
        dfs(i + 1, j, A, b);
    return;
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &A)
{
    n = A.size();
    m = A[0].size();
    vector<vector<int>> blue(n, vector<int>(m, 0));
    vector<vector<int>> red(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++)
        dfs(0, i, A, blue);
    for (int i = 1; i < n; i++)
        dfs(i, 0, A, blue);
    for (int i = 0; i < n; i++)
        dfs(i, m - 1, A, red);
    for (int i = m - 2; i >= 0; i--)
        dfs(n - 1, i, A, red);
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blue[i][j] == 1 && red[i][j] == 1)
                ans.push_back(vector<int>{i, j});
        }
    }

    return ans;
}