#include <bits/stdc++.h>
using namespace std;

bool cycleDFS(int i, int parent, vector<int> &visited, vector<int> adj[])
{
    visited[i] = 1;

    for (auto it : adj[i])
    {
        if (visited[it] == 0)
        {
            if (cycleDFS(it, i, visited, adj))
            {
                return true;
            }
        }
        else if (it != parent)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int v, E;
    cin >> v >> E;
    vector<int> adj[v];

    for (int i = 0; i < E; i++)
    {
        int u, v1;
        cin >> u >> v1;
        adj[u].push_back(v1);
        adj[v1].push_back(u);
    }

    vector<int> visited(v, 0);
    int ans = 0;

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            if (cycleDFS(i, -1, visited, adj))
            {
                ans = 1;
            }
        }
    }

    if (ans)
    {
        cout << "cycle present\n";
    }
    else
    {
        cout << "cycle not present\n";
    }

    cout << endl;
}