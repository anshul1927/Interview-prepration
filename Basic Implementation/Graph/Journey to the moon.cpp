#include <bits/stdc++.h>
using namespace std;

int dfs(int i, vector<int> adj[], int visited[])
{
    visited[i] = 1;
    int size = 1;
    for (auto it : adj[i])
    {
        if (!visited[it])
        {
            size = size + dfs(it, adj, visited);
        }
    }

    return size;
}
int main()
{

    int n, p;
    cin >> n >> p;

    int p1, p2;
    vector<int> adj[n];

    for (int i = 0; i < p; i++)
    {
        cin >> p1 >> p2;
        adj[p1].push_back(p2);
    }

    int visited[n];
    vector<int> noofverticesineachcomponent;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            noofverticesineachcomponent.push_back(dfs(i, adj, visited));
        }
    }
    int ans = n * (n - 1) / 2;
    for (auto el : noofverticesineachcomponent)
    {
        ans -= el * (el - 1) / 2;
    }
    cout << "total no of ways to choose a pair of astronauts is " << ans << endl;
    return 0;
}