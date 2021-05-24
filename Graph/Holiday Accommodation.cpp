// SPOJ Problem

#include <bits/stdc++.h>

const int N = 100 * 1000 + 10;

std::vector<std::pair<int, int>> adj[N];
int visited[N];
int count[N]; //
long long ans;
int n;

void dfs(int node)
{
    visited[node] = true;
    count[node] = 1;

    for (auto el : adj[node])
    {
        int nbr = el.first;
        int wt = el.second;
        if (!visited[nbr])
        {
            dfs(nbr);
            ans += std::min(count[nbr], n - count[nbr]) * 2ll * wt;
            count[node] += count[nbr];
        }
    }
}

int main()
{

    int t;
    std::cin >> t;
    int t1 = t;
    int index = 1;
    while (t--)
    {
        std::cin >> n;
        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
            visited[i] = false;
            count[i] = 1;
        }
        int p1, p2, p3;
        for (int i = 0; i < n - 1; i++)
        {
            std::cin >> p1 >> p2 >> p3;
            adj[p1 - 1].push_back({p2 - 1, p3});
            adj[p2 - 1].push_back({p1 - 1, p3});
        }

        ans = 0;
        dfs(0);
        std::cout << "Case #" << index << ": " << ans << "\n";
        index++;
    }
    return 0;
}