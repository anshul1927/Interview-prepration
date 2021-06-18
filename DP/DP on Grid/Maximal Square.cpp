// lc 221
//https://leetcode.com/problems/maximal-square/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();

        int dp[m + 1][n + 1];
        int ans = 0;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    // cout<<i<<" "<<j<<endl;
                    dp[i][j] = 0;
                }
                else if (matrix[i - 1][j - 1] == '1')
                {
                    // cout<<i<<" "<<j<<endl;
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        return ans * ans;
    }
};

int main()
{
    int n;
    cin >> n;
}