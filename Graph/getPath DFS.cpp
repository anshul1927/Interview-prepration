#include <bits/stdc++.h>
using namespace std;

vector<int> dfs(int start, int end, int v, vector<int> adj[], vector<int> &visited)
{
    vector<int> ans;
    if (start == end)
    {
        ans.push_back(start);
        return ans;
    }

    visited[start] = 1;

    for (auto it : adj[start])
    {
        if (!visited[it])
        {
            ans = dfs(it, end, v, adj, visited);
            if (ans.size() > 0)
            {
                ans.push_back(start);
                return ans;
            }
        }
    }
    return ans;
}

vector<int> hasPath(int start, int end, int v, vector<int> adj[])
{

    vector<int> visited(v + 1, 0);
    vector<int> ans = dfs(start, end, v, adj, visited);

    return ans;
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
        adj[v1].push_back(u);
    }
    int start, end;
    cin >> start >> end;
    vector<int> ans;
    ans = hasPath(start, end, v, adj);

    if (ans.size() == 0)
    {
        cout << "path didn't exist";
    }
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    cout << endl;
}