#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int start, int end, int v, vector<int> adj[], vector<int> &visited)
{
    vector<int> ans;
    if (start == end)
    {
        ans.push_back(start);
        return ans;
    }

    queue<int> q;
    q.push(start);

    map<int, int> m;
    m.insert({start, -1});

    visited[start] = 1;

    bool flag = false;
    while (!q.empty())
    {

        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                q.push(it);
                m.insert({it, node});
                if (it == end)
                {
                    flag = true;
                    break;
                }
                visited[it] = 1;
            }
        }
    }

    if (flag)
    {
        int end1 = end;
        ans.push_back(end1);
        while (end1 != start)
        {
            int a = m.at(end1);
            ans.push_back(a);
            end1 = a;
        }
    }

    return ans;
}

vector<int> hasPath(int start, int end, int v, vector<int> adj[])
{

    vector<int> visited(v + 1, 0);
    vector<int> ans = bfs(start, end, v, adj, visited);

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