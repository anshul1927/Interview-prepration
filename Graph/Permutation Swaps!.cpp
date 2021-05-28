// https://www.interviewbit.com/problems/permutation-swaps/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, int node, unordered_set<int> &component, vector<int> &visited)
{

    visited[node] = 1;
    component.insert(node);

    for (auto it : adj[node])
    {
        if (visited[it] == 0)
        {
            dfs(adj, it, component, visited);
        }
    }
}

vector<unordered_set<int>> getComponent(vector<vector<int>> &adj, int n)
{
    vector<int> visited(n + 1, 0);
    vector<unordered_set<int>> output;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            unordered_set<int> component;
            dfs(adj, i, component, visited);
            output.push_back(component);
        }
    }
    return output;
}

int solve(vector<int> &A, vector<int> &B, vector<vector<int>> &C)
{

    vector<vector<int>> adj(A.size() + 1);

    for (auto el : C)
    {
        adj[el[0]].push_back(el[1]);
        adj[el[1]].push_back(el[0]);
    }
    int count = 0;
    vector<unordered_set<int>> component = getComponent(adj, adj.size() - 1);
    for (auto s : component)
    {
        vector<int> index;
        for (auto it : s)
        {
            index.push_back(it);
        }
        unordered_set<int> check;
        for (auto it : index)
        {
            check.insert(A[it - 1]);
            check.insert(B[it - 1]);
        }
        if (s.size() == check.size())
        {
            count++;
        }
    }

    if (count == component.size())
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> B(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    int e;
    cin >> e;

    vector<vector<int>> C(e);

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;

        C[i].push_back(x);
        C[i].push_back(y);
    }
    cout << solve(A, B, C);
    return 0;
}