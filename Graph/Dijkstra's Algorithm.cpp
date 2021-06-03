#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &adj, int n, int src)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> distance(n, INT_MAX);

    distance[src] = 0;

    pq.push({0, src});

    while (!pq.empty())
    {
        // int dist = pq.top().first;
        int node = pq.top().second;

        pq.pop();
        for (auto it : adj[node])
        {
            int nextnode = it.first;
            int nextdistance = it.second;
            if (distance[nextnode] > distance[node] + nextdistance)
            {
                distance[nextnode] = distance[node] + nextdistance;
                pq.push({distance[nextnode], nextnode});
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

    vector<vector<pair<int, int>>> adj(n);

    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    int src;
    cin >> src;
    dijkstra(adj, n, src);
    return 0;
}