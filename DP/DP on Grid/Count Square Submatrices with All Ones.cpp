// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// lc 1277

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();

        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1)
                    if (i == 0 || j == 0)
                    {
                        res += matrix[i][j];
                    }
                    else
                    {
                        int temp_cell_value = min(matrix[i - 1][j], min(matrix[i][j - 1], matrix[i - 1][j - 1])) + matrix[i][j];
                        res += temp_cell_value;
                        matrix[i][j] = temp_cell_value;
                    }
            }
        }

        return res;
    }
};
int main()
{
    int n;
    cin >> n;
}