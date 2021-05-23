//https://www.interviewbit.com/problems/nqueens/

#include <bits/stdc++.h>
using namespace std;

bool validBoard(int row, int col, int n, vector<string> &board)
{

    int r = row;
    int c = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    row = r;
    col = c;

    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    row = r;
    col = c;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}

void solveNQueen(int col, int n, vector<string> &board, vector<vector<string>> &ans)
{

    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (validBoard(row, col, n, board))
        {
            board[row][col] = 'Q';
            solveNQueen(col + 1, n, board, ans);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> Solution::solveNQueens(int A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<string>> ans;
    vector<string> board(A);
    string s(A, '.');

    for (int i = 0; i < A; i++)
    {
        board[i] = s;
    }

    solveNQueen(0, A, board, ans);
    return ans;
}