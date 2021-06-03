// Bridges in a Graph is which edge whose removal makes a graph in 2 or more component.

#include <bits/stdc++.h>
using namespace std;

/* we use 2 array 
        1. Time of insertation of each edge.
        2. Lowest time of insertation.

        bridge possible only when :- 
            low_time[adjacent_node] > time_of_insertion[current_node]
*/

void dfs(int node, int parent, vector<int> &visited, vector<int> &time_of_insertion, vector<int> &low_time, vector<vector<int>> &adj, int &timer)
{
    visited[node] = 1;
    time_of_insertion[node] = low_time[node] = timer++;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;

        if (visited[it] == 0)
        {
            dfs(it, parent, visited, time_of_insertion, low_time, adj, timer);
            low_time[node] = min(low_time[node], low_time[it]);
            if (low_time[it] > time_of_insertion[node])
            {
                cout << it << "-->" << node << endl;
            }
        }
        else
        {
            low_time[node] = min(low_time[node], time_of_insertion[it]);
        }
    }
}

int main()
{

    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n);

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> time_of_insertion(n, -1);
    vector<int> low_time(n, -1);
    vector<int> visited(n, 0);

    int timer = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, -1, visited, time_of_insertion, low_time, adj, timer);
        }
    }

    return 0;
}