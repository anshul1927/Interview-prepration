//https://leetcode.com/problems/course-schedule/
// lc 207

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool cycle(vector<vector<int>> &G, int v)
    {

        vector<int> in_degree(v, 0);

        for (int i = 0; i < v; i++)
        {
            for (auto it : G[i])
            {
                in_degree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < v; i++)
        {
            if (in_degree[i] == 0)
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
            for (auto el : G[node])
            {
                in_degree[el]--;
                if (in_degree[el] == 0)
                {
                    q.push(el);
                }
            }
        }

        return (cnt == v);
    }

    bool canFinish(int A, vector<vector<int>> &B)
    {

        vector<vector<int>> graph(A);
        int n = B.size();
        for (int i = 0; i < n; i++)
        {
            graph[B[i][0]].push_back(B[i][1]);
        }

        return cycle(graph, A);
    }
};