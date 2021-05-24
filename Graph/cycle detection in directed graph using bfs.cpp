// TC = O(N + E)

#include <bits/stdc++.h>
using namespace std;

bool topologicalsort(vector<int> adj[], int v)
{
    vector<int> indegree(v, 0);

    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int cnt = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return (cnt == v);
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
    if (topologicalsort(adj, v))
    {
        cout << "not cycle";
    }
    else
    {
        cout << "cycle";
    }

    cout << endl;
}