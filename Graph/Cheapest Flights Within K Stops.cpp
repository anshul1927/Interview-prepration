// lc 787
// https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &adj, int n, int src, int dest, int k)
{

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;


    pq.push({0, {k + 1, src}});
    int total = 0;

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second.second;
        int count = pq.top().second.first;
        total++;

        cout << "node :- " << node << " distance :- " << dist << " k :- " << count << endl;
        pq.pop();

        if (node == dest) {
            cout<<"dist "<<dist<<endl;
        }
        if (count > 0)
            for (auto it : adj[node])
            {
                int nextnode = it.first;
                int nextdistance = it.second;

                pq.push({nextdistance + dist, {count - 1, nextnode}});

            }
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
    }
    int src;
    cin >> src;
    int dest;
    cin >> dest;
    int k;
    cin >> k;
    cout << "##" << k << endl;
    dijkstra(adj, n, src, dest, k);
    return 0;
}