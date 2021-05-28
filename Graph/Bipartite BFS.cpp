#include <bits/stdc++.h>
using namespace std;

bool bipartite(int i, vector<int> adj[], int color[])
{

    queue<int> q;
    q.push(i);
    color[i] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                q.push(it);
                color[it] = 1 - color[node];
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int v)
{
    int color[v];
    memset(color, -1, sizeof color);
    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartite(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
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

    if (checkBipartite(adj, v))
    {
        cout << "Graph is Bipartite\n";
    }
    else
    {
        cout << "Graph is not Bipartite\n";
    }

    cout << endl;
}