#include <bits/stdc++.h>
using namespace std;

struct node
{
    int u;
    int v;
    int wt;

    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node n1, node n2)
{
    return n1.wt < n2.wt;
}

int findPr(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return findPr(parent[u], parent);
}

void unionfind(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPr(u, parent);
    v = findPr(v, parent);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else
        parent[v] = u;
    rank[u]++;
}

int main()
{

    int n, e;
    cin >> n >> e;
    vector<node> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    vector<int> rank(n, 0);

    int cost = 0;

    vector<pair<int, int>> mst;

    for (auto it : edges)
    {
        if (findPr(it.v, parent) != findPr(it.u, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionfind(it.u, it.v, parent, rank);
        }
    }
    cout << cost << endl;
    for (auto it : mst)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}