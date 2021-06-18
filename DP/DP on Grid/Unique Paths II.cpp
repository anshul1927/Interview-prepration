//https://leetcode.com/problems/unique-paths-ii/
// lc63

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {

        if (obstacleGrid[0][0] == 1)
        {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int dp[m][n];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    if (obstacleGrid[i][j] == 1)
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        dp[i][j] = 1;
                    }
                }
                else if (i == 0)
                {
                    if (obstacleGrid[i][j] == 1)
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
                else if (j == 0)
                {
                    if (obstacleGrid[i][j] == 1)
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
                else
                {
                    if (obstacleGrid[i][j] == 1)
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    int n;
    cin >> n;
}