// https://leetcode.com/problems/surrounded-regions/
// lc 130

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &board, int row, int col)
    {

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != 'O')
        {
            return;
        }

        // bool b1 = ;
        // bool b2 = ;
        // bool b3 = ;
        // bool b4 = ;
        board[row][col] = '#';

        dfs(board, row + 1, col);
        dfs(board, row, col + 1);
        dfs(board, row - 1, col);
        dfs(board, row, col - 1);
    }
    void solve(vector<vector<char>> &board)
    {

        int m = board.size();
        if (m == 0)
        {
            return;
        }

        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }

        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
                dfs(board, 0, i);
            if (board[m - 1][i] == 'O')
                dfs(board, m - 1, i);
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};