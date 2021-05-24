// https://leetcode.com/problems/number-of-islands/
// lc 200

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int row, int col, vector<vector<char>> &grid)
    {

        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1')
        {
            return;
        }

        grid[row][col] = '2';

        dfs(row + 1, col, grid);
        dfs(row, col + 1, grid);
        dfs(row, col - 1, grid);
        dfs(row - 1, col, grid);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }

        return ans;
    }
};