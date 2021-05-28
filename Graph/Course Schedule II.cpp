// lc 210
// https://leetcode.com/problems/course-schedule-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topologicalsort(vector<vector<int>> &adj, int v)
    {
        vector<int> indegree(v, 0);

        for (int i = 0; i < v; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        int cnt = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
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
        cout << cnt;
        if (cnt != v)
        {
            return {};
        }
        return topo;
    }

    vector<int> findOrder(int A, vector<vector<int>> &B)
    {
        vector<vector<int>> graph(A);
        int n = B.size();
        for (int i = 0; i < n; i++)
        {
            graph[B[i][0]].push_back(B[i][1]);
        }

        vector<int> ans = topologicalsort(graph, A);

        return vector(ans.rbegin(), ans.rend());
    }
};