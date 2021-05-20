#include <bits/stdc++.h>
using namespace std;

bool hasPath(int start, int end, int v, vector<int> adj[])
{

    vector<int> visited(v + 1, 0);

    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (node == end)
        {
            return true;
        }

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = 1;
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
        adj[v1].push_back(u);
    }
    int start, end;
    cin >> start >> end;

    if (hasPath(start, end, v, adj))
    {
        cout << "this graph have path between " << start << " to " << end << endl;
    }
    else
    {
        cout << "no path";
    }
    cout << endl;
}