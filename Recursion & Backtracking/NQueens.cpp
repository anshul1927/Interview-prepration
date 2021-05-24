#include <bits/stdc++.h>
using namespace std;

bool isValidBoard(int row, int col, vector<string> &board, int n)
{

    int r = row;
    int c = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col--;
    }

    row = r;
    col = c;

    while (col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        col--;
    }

    col = c;
    row = r;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row++;
        col--;
    }

    return true;
}
void solveNqueens(int col, int n, vector<string> &board, vector<vector<string>> &ans)
{

    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isValidBoard(row, col, board, n))
        {
            board[row][col] = 'Q';
            solveNqueens(col + 1, n, board, ans);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');

    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    solveNqueens(0, n, board, ans);
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<string>> ans;
    ans = solveNQueens(n);

    for (auto board : ans)
    {
        for (auto s : board)
        {
            cout << s << "\n";
        }
        cout << endl;
    }

    return 0;
}