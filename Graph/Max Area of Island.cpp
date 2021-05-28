// lc695
//https://leetcode.com/problems/max-area-of-island/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &grid, int &area)
    {

        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != 1)
        {
            return;
        }

        grid[row][col] = 2;
        area++;

        dfs(row + 1, col, grid, area);
        dfs(row, col + 1, grid, area);
        dfs(row, col - 1, grid, area);
        dfs(row - 1, col, grid, area);
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    int area = 0;
                    dfs(i, j, grid, area);
                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};