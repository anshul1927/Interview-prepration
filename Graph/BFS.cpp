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
    }

    vector<int> visited(v, 0);
    vector<int> bfs;

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            queue<int> q;
            q.push(0);
            visited[0] = true;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                bfs.push_back(node);

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

    for (int i = 0; i < bfs.size(); i++)
    {
        cout << bfs[i] << " ";
    }
    cout << endl;
}