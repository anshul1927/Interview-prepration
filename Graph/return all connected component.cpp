#include <bits/stdc++.h>
using namespace std;

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

    vector<int> visited(v, 0);

    int cnt = 0;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            cnt++;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (auto it : adj[node])
                {
                    if (!visited[it])
                    {
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }

    cout << "Graph have " << cnt << " connected component";
    cout << endl;
}