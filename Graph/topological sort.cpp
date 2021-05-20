// TC = O(N + E)

#include <bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector<int> adj[], stack<int> &st, int visited[])
{
    visited[node] = 1;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            findTopoSort(it, adj, st, visited);
        }
    }
    st.push(node);
}

vector<int> topologicalsort(vector<int> adj[], int v)
{
    int visited[v];
    stack<int> st;

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            findTopoSort(i, adj, st, visited);
        }
    }
    vector<int> topo;

    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
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

    vector<int> ans = topologicalsort(adj, v);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}