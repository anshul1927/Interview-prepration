#include <bits/stdc++.h>
using namespace std;

int dfs(long long int i, vector<long long int> adj[], long long int visited[])
{
    visited[i] = 1;
    long long int size = 1;
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

    long long int n, p;
    cin >> n >> p;

    long long int p1, p2;
    vector<long long int> adj[n];

    for (long long int i = 0; i < p; i++)
    {
        cin >> p1 >> p2;
        adj[p1].push_back(p2);
        adj[p2].push_back(p1);
    }

    long long int visited[n];
    vector<long long int> noofverticesineachcomponent;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            noofverticesineachcomponent.push_back(dfs(i, adj, visited));
        }
    }

    // for (auto it : noofverticesineachcomponent) {
    //     cout << it << " ";
    // }
    // cout << endl;
    cout<<noofverticesineachcomponent.size()<<endl;
    long long int ans = n * (n - 1) / 2;
    cout<<ans<<endl;
    for (auto el : noofverticesineachcomponent)
    {
        ans -= el * (el - 1) / 2;
    }
    cout << "total no of ways to choose a pair of astronauts is " << ans << endl;
    return 0;
}