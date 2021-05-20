#include <bits/stdc++.h>
using namespace std;

bool cycle(int node, vector<int> adj[], int visited[], int dfsvisited[])
{
    visited[node] = 1;
    dfsvisited[node] = 1;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            if (cycle(it, adj, visited, dfsvisited) == true)
            {
                return true;
            }
        }
        else if (dfsvisited[it] == 1)
        {
            return true;
        }
    }
    dfsvisited[node] = 0;
    return false;
}

bool checkCycle(vector<int> adj[], int v)
{
    int visited[v];
    int dfsvisited[v];

    memset(visited, 0, sizeof(visited));
    memset(dfsvisited, 0, sizeof(dfsvisited));

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (cycle(i, adj, visited, dfsvisited))
            {
                return true;
            }
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
    }

    if (checkCycle(adj, v))
    {
        cout << "Cycle\n";
    }
    else
    {
        cout << "not cycle\n";
    }

    cout << endl;
}