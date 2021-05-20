#include <bits/stdc++.h>
using namespace std;

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
    int cnt = 0;
    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cnt++;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }

    if (cnt == v)
    {
        cout << "Graph is connected";
    }
    else
    {
        cout << "Graph is not connected";
    }
    cout << endl;
}