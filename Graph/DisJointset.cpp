#include <bits/stdc++.h>
using namespace std;

int parent[100000], rank[100000];
int n = 100000;

void makeSet()
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findPr(int node)
{
    if (node == parent[node])
        return node;

    return parent[node] = findPr(parent[node]);
}

void unionFind(int u, int v)
{
    u = findPr(u);
    v = findPr(v);

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else
    {
        parent[u] = v;
        rank[u]++;
    }
}

int main()
{
    makeSet();
    int m;
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        unionFind(x, y);
    }
    if (findPr(2) != findPr(3))
    {
        cout << "Different Component";
    }
    else
    {
        cout << "Same Component";
    }
}