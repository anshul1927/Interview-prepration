#include <bits/stdc++.h>
using namespace std;

int Solution::solve(int A, vector<vector<int>> &B)
{

    vector<int> adj[A + 1];

    for (int i = 0; i < B.size(); i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
    }
    vector<int> indegree(A + 1, 0);

    for (int i = 1; i <= A; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= A; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int cnt = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    return (cnt == A ? 0 : 1);
}
