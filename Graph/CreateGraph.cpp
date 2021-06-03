#include <bits/stdc++.h>
using namespace std;

class Graph
{

    int n;
    vector<vector<int>> adj;
    vector<vector<pair<int, int>>> adj_w;

public:
    Graph(int n, bool weight)
    {
        this->n = n;
        if (weight)
        {
            adj_w.resize(n);
        }
        else
        {
            adj.resize(n);
        }
    }

    void addEdge(int x, int y, bool bidir)
    {
        adj[x].push_back(y);
        if (bidir)
        {
            adj[y].push_back(x);
        }
    }

    void addEdge(int x, int y, int weight, int bidir)
    {
        adj_w[x].push_back({y, weight});
        if (bidir)
        {
            adj_w[y].push_back({x, weight});
        }
    }
};