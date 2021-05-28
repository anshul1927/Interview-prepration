#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, int n, int src)
{

    vector<int> distance(n, INT_MAX);

    queue<int> q;
    distance[src] = 0;

    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (distance[node] + 1 < distance[it])
            {
                distance[it] = distance[node] + 1;
                q.push(it);
            }
        }
    }

    for (auto it : distance)
    {
        cout << it << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    int e;
    cin >> e;

    vector<vector<int>> adj(n);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int src;
    cin >> src;

    bfs(adj, n, src);
    return 0;
}