#include <bits/stdc++.h>
using namespace std;

void toposort(vector<vector<int>> &adj, stack<int> &s, int src, vector<int> &visited)
{
    visited[src] = 1;

    for (auto it : adj[src])
    {
        if (visited[it] == 0)
        {
            toposort(adj, s, it, visited);
        }
    }
    cout << "src is " << src << "  --> ";

    s.push(src);
    cout << s.top() << endl;
}

void SSC(vector<vector<int>> &rev_adj, vector<int> &rev_visited, int src, vector<int> &result)
{
    rev_visited[src] = 1;
    result.push_back(src);

    for (auto it : rev_adj[src])
    {
        if (rev_visited[it] == 0)
        {
            SSC(rev_adj, rev_visited, it, result);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int e;
    cin >> e;
    vector<vector<int>> adj(n);
    vector<vector<int>> rev_adj(n);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        rev_adj[y].push_back(x);
    }
    stack<int> s;
    vector<int> visited(n, 0);
    vector<int> rev_visited(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            toposort(adj, s, i, visited);
        }
    }

    vector<vector<int>> ans;
    vector<int> result;

    int stack_size = s.size();

    for (int i = 0; i < stack_size; i++)
    {
        if (rev_visited[s.top()] == 0)
        {
            cout << i << endl;
            result.clear();
            SSC(rev_adj, rev_visited, s.top(), result);
            ans.push_back(result);
        }
        s.pop();
    }
    cout << "Total no of strongly connected component is " << ans.size() << endl;
    for (auto it : ans)
    {
        for (auto el : it)
        {
            cout << el << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}