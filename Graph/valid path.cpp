#include <bits/stdc++.h>
using namespace std;

int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

bool dfs(vector<vector<int>> &board, int sx, int sy, int destx, int desty)
{

    if (sx == destx && sy == desty)
    {
        if (board[sx][sy] != 0)
            return true;
        return false;
    }
    if (board[sx][sy] == 0 or board[sx][sy] == 2)
    {
        return false;
    }

    board[sx][sy] = 2;

    bool ans = false;
    for (int i = 0; i < 8; i++)
    {
        if (sx + dx)
            if ((sx + dx[i] <= destx) && (sx + dx[i]) >= 0 && (sy + dy[i]) <= desty && (sy + dy[i]) >= 0)
            {
                ans = ans || dfs(board, sx + dx[i], sy + dy[i], destx, desty);
            }
    }

    return ans;
}

int main()
{
    int x, y, N, R;
    cin >> x >> y >> N >> R;

    int A[N];
    int B[N];

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    vector<vector<int>> board(x + 1, vector<int>(y + 1, 1));

    for (int i = 0; i < N; i++)
    {
        int x1 = A[i] - R;
        int x2 = A[i] + R;
        int y1 = B[i] - R;
        int y2 = B[i] + R;

        board[A[i]][B[i]] = 0;

        for (int j = x1; j <= x2; j++)
        {
            for (int k = y1; k <= y2; k++)
            {
                // cout << "j is " << j << " k is " << k << endl;
                if (j >= 0 && j <= x && k <= y && k >= 0)
                {
                    board[j][k] = 0;
                }
            }
        }
    }

    // for (auto el : board)
    // {
    //     for (auto i : el)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    cout << endl;
    bool ans = dfs(board, 0, 0, x, y);
    cout << ans << endl;

    // for (auto el : board)
    // {
    //     for (auto i : el)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}