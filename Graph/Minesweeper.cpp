// lc 529
// https://leetcode.com/problems/minesweeper/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
    int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
    vector<vector<int>> visited;
    bool check(int row, int col, int m, int n)
    {
        if (row < 0 or row >= m or col < 0 or col >= n)
        {
            return false;
        }
        return true;
    }
    void solve(vector<vector<char>> &board, int row, int col, int m, int n)
    {

        if (visited[row][col] == 0)
        {
            if (board[row][col] == 'E')
            {
                board[row][col] = 'B';
                for (int i = 0; i < 8; i++)
                {
                    if (check(row + dx[i], col + dy[i], m, n))
                    {
                        solve(board, row + dx[i], col + dy[i], m, n);
                    }
                }
            }
            else if (board[row][col] == 'B' || board[row][col] == 'M')
            {
                return;
            }
        }
        else
        {
            board[row][col] = '0' + visited[row][col];
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        if (board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        int m = board.size();
        int n = board[0].size();
        visited.clear();

        visited.resize(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'M')
                {
                    for (int k = 0; k < 8; k++)
                    {
                        if (check(i + dx[k], j + dy[k], m, n))
                        {
                            if (board[i + dx[k]][j + dy[k]] != 'M')
                                visited[i + dx[k]][j + dy[k]]++;
                        }
                    }
                }
            }
        }

        solve(board, click[0], click[1], m, n);
        return board;
    }
};