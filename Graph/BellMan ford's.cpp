// it detect -ve edge cycle in graph
// not worked if -ve edge cycle is present in graph but it will tell if graph have -ve edge cycle present or not.
// if graph is directed then edges weight could be +ve or -ve but if graph is un-directed then we have to make graph first as directed graph.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<pair<int, int>, int>> adj(e);

    for (int i = 0; i < e; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        adj.push_back({{x, y}, z});
    }

    vector<int> distance(n, INT_MAX);
    distance[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : adj)
        {
            int u = it.first.first;
            int v = it.first.second;
            int w = it.second;

            if ((distance[u] == INT_MAX && distance[v] == INT_MAX) || (distance[u] == INT_MAX && distance[v] != INT_MAX))
            {
                continue;
            }
            else if (distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
            }
        }
    }

    for (auto it : distance)
    {
        cout << it << " ";
    }
    cout << endl;
    int flag = 0;
    for (auto it : adj)
    {
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;

        if ((distance[u] == INT_MAX && distance[v] == INT_MAX) || (distance[u] == INT_MAX && distance[v] != INT_MAX))
        {
            continue;
        }
        else if (distance[u] + w < distance[v])
        {
            flag = 1;
            distance[v] = distance[u] + w;
        }
    }

    if (flag == 1)
    {
        cout << "graph have -ve edge cycle" << endl;
    }
    else
    {
        cout << "Graph don't have -ve edge cycle" << endl;
    }

    return 0;
}