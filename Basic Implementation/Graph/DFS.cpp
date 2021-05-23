#include <bits/stdc++.h>
using namespace std;

void DFS(int i, vector<int> &visited, vector<int> adj[], vector<int> &dfs)
{
    dfs.push_back(i);
    visited[i] = 1;

    for (auto it : adj[i])
    {
        if (!visited[it])
        {
            DFS(it, visited, adj, dfs);
        }
    }
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
    vector<int> dfs;

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            DFS(i, visited, adj, dfs);
        }
    }

    for (int i = 0; i < dfs.size(); i++)
    {
        cout << dfs[i] << " ";
    }
    cout << endl;
}