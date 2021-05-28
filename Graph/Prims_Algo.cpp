/*

In prims algorithm :-
    first choose a vertex from where algo start.
    then choose minimum edge weight edge attach to node that which we selected
    then we have 2 nodes which are connected.
    now check minimum edge which are connected to the both the 2 nodes which we selected above and attach to the it's adjacent already selected
    node.   
    do  it again.
*/

#include <bits/stdc++.h>
using namespace std;

void MST(vector<vector<pair<int, int>>> &adj, vector<int> &key, vector<bool> &mst, vector<int> &parent, int src, vector<vector<pair<int, int>>> &ans)
{
    int index;
    bool flag = false;
    int minimumedgeweight = INT_MAX;
    for (int i = 0; i < key.size(); i++)
    {
        if (mst[i] == false)
        {
            flag = true;
            if (minimumedgeweight > key[i])
            {
                minimumedgeweight = key[i];
                index = i;
            }
        }
    }
    mst[index] = true;
    for (auto it : adj[index])
    {
        int v = it.first;
        int weight = it.second;

        if (mst[v] == false && weight < key[v])
        {
            key[v] = weight;
            parent[v] = src;
        }
    }
    if (parent[index] != -1)
        ans[parent[index]].push_back({index, minimumedgeweight});
    if (flag == false)
    {
        return;
    }
    MST(adj, key, mst, parent, index, ans);
}

int main()
{

    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> adj(n);
    vector<vector<pair<int, int>>> ans(n);

    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;

    MST(adj, key, mst, parent, 0, ans);

    int minimumcost = 0;
    for (auto it : ans)
    {
        for (auto el : it)
        {
            cout << el.first << "-->" << el.second << " ";
            minimumcost += el.second;
        }
        cout << endl;
    }

    cout << "Minimum cost for this graph is :- " << minimumcost << endl;
    return 0;
}