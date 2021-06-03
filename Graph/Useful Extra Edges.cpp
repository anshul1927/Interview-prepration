// https://www.interviewbit.com/problems/useful-extra-edges/


#include <bits/stdc++.h>
using namespace std;




int dijkstra(vector<vector<pair<int, int>>> & adj, int C, int n, int dest) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> distance(n + 1, INT_MAX);

    distance[C] = 0;
    pq.push({0, C});

    while (!pq.empty()) {

        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int nextnode = it.first;
            int nextnodedistance = it.second;

            if (distance[nextnode] > distance[node] + nextnodedistance) {
                distance[nextnode] = distance[node] + nextnodedistance;
                pq.push({distance[nextnode], nextnode});
            }
        }
    }

    return distance[dest];
}

int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {

    vector<vector<pair<int, int>>> adj(A + 1);
    for (auto it : B) {
        adj[it[0]].push_back({it[1], it[2]});
    }

    int ans = INT_MAX;
    for (auto it : E) {

        if (it[0] > A || it[1] > A) {
            continue;
        }

        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});

        ans = min (ans, dijkstra(adj, C, A, D));
        adj[it[0]].pop_back();
        adj[it[1]].pop_back();
    }

    return ans == INT_MAX ? -1 : ans;
}
ś