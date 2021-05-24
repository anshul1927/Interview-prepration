// https://leetcode.com/problems/snakes-and-ladders/
// https://www.interviewbit.com/problems/snake-ladder-problem/ this problem have a some variation in input format

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int board[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    vector<int> adj[n * n];
    int firstindex = n;
    int flag = 0;
    int vertice = 0;
    int number = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int row = n - i;
        if (row % 2 == 1)
        {
            cout << "==1 block \n";
            for (int j = 0; j < n; j++)
            {

                for (int dice = 1; dice + vertice < n * n && dice <= 6; dice++)
                {
                    int k = vertice + dice;
                    int x, y;

                    x = n - (k / n) - 1;

                    if (n % 2 == 0)
                    {
                        if (x % 2 != 0)
                        {
                            y = k % n;
                        }
                        else
                        {
                            y = n - (k % n) - 1;
                        }
                    }
                    else
                    {
                        if (x % 2 != 0)
                        {
                            y = n - (k % n) - 1;
                        }
                        else
                        {
                            y = k % n;
                        }
                    }

                    if (board[x][y] != -1)
                    {
                        adj[vertice].push_back(board[x][y] - 1);
                    }
                    else
                    {
                        adj[vertice].push_back(k);
                    }
                }

                vertice++;
            }
        }
        else
        {
            cout << "==0 block \n";
            for (int j = n - 1; j >= 0; j--)
            {
                for (int dice = 1; dice + vertice < n * n && dice <= 6; dice++)
                {
                    int k = vertice + dice;
                    int x, y;

                    x = n - (k / n) - 1;

                    if (n % 2 == 0)
                    {
                        if (x % 2 != 0)
                        {
                            y = k % n;
                        }
                        else
                        {
                            y = n - (k % n) - 1;
                        }
                    }
                    else
                    {
                        if (x % 2 != 0)
                        {
                            y = n - (k % n) - 1;
                        }
                        else
                        {
                            y = k % n;
                        }
                    }

                    if (board[x][y] != -1)
                    {
                        adj[vertice].push_back(board[x][y] - 1);
                    }
                    else
                    {
                        adj[vertice].push_back(k);
                    }
                }
                vertice++;
            }
        }
    }

    vector<int> visited(n * n, -1);
    visited[0] = 0;

    queue<int> q;

    q.push(0);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (node == n * n - 1)
        {
            break;
        }

        for (auto el : adj[node])
        {
            if (visited[el] == -1)
            {
                visited[el] = visited[node] + 1;
                q.push(el);
            }
        }
    }

    cout << "path is " << visited[n * n - 1] << endl;

    int count = 0;
    for (auto el : adj)
    {
        cout << count << " --> ";
        for (auto edge : el)
        {
            cout << edge << " ";
        }
        cout << endl;
        count++;
    }

    cout << "anshul";
    return 0;
}

// Optimized solution

int main()
{
    int n;
    cin >> n;

    int board[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    int l = n * n;
    int simpleboard[l];

    int index = 0;
    int vis[l];

    queue<pair<int, int>> q;
    bool flag = false;

    memset(vis, -1, sizeof vis);

    for (int i = n - 1; i >= 0; i--)
    {

        if (flag == false)
        {
            for (int j = 0; j < n; j++)
            {
                simpleboard[index++] = board[i][j];
            }
            flag = true;
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                simpleboard[index++] = board[i][j];
            }
            flag = false;
        }
    }

    q.push({0, 0});
    vis[0] = 0;

    while (!q.empty())
    {

        int node = q.front().first;
        int dest = q.front().second;
        if (node == l - 1)
        {
            cout << dest << endl;
            break;
        }
        q.pop();

        for (int i = node + 1; i <= node + 6 && i < l; i++)
        {
            if (vis[i] == -1)
            {

                vis[i] = 1;
                if (simpleboard[i] == -1)
                {
                    q.push({i, dest + 1});
                }
                else
                {
                    q.push({simpleboard[i] - 1, dest + 1});
                }
            }
        }
    }

    return 0;
}