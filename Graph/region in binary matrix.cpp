#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &board, int row, int col)
{
    if (row < 0 or row >= board.size() or col < 0 or col >= board[0].size() or board[row][col] != 1)
    {
        return 0;
    }

    board[row][col] = 2;

    return (1 +
            dfs(board, row + 1, col) +
            dfs(board, row, col + 1) +
            dfs(board, row - 1, col) +
            dfs(board, row, col - 1) +
            dfs(board, row - 1, col - 1) +
            dfs(board, row - 1, col + 1) +
            dfs(board, row + 1, col - 1) +
            dfs(board, row + 1, col + 1));
}
int main()
{

    int m, n;

    cin >> m >> n;

    vector<vector<int>> board(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                ans = max(ans, dfs(board, i, j));
            }
        }
    }

    cout << ans;
    return 0;
}