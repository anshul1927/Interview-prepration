// https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &G, int root, vector<int> &visited, int &maxdist)
{

    priority_queue<int> q;

    visited[root] = 1;
    for (auto it : G[root])
    {
        if (visited[it] == 0)
        {
            q.push(dfs(G, it, visited, maxdist) + 1);
        }
    }

    if (!q.empty())
    {
        int max1 = q.top();
        q.pop();

        if (!q.empty())
        {
            int max2 = q.top();
            if (max1 + max2 > maxdist)
                maxdist = max1 + max2;
        }

        if (max1 > maxdist)
            maxdist = max1;
        return max1;
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> G(n);
    int root;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
        {
            root = i;
        }
        else
        {
            G[a[i]].push_back(i);
            G[i].push_back(a[i]);
        }
    }
    vector<int> visited(n, 0);
    int maxdist = 0;

    dfs(G, root, visited, maxdist);
    cout << maxdist;
    return 0;
}