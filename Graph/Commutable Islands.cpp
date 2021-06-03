// https://www.interviewbit.com/problems/commutable-islands/

#include <bits/stdc++.h>
using namespace std;

int Solution::solve(int n, vector<vector<int> > &B) {
    
    vector<vector<pair<int, int>>> adj(n);
        int ans=0;
 
    for(auto el: B){
        adj[el[0]-1].push_back({el[1]-1,el[2]});
        adj[el[1]-1].push_back({el[0]-1,el[2]});
    }
    
    
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n);
    
    key[0] = 0;
    parent[0] = -1;
    
    
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        mst[u] = true;
        
        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            
            if(mst[v] == false && w<key[v]){
                parent[v] = u;
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }
    
    for(auto it: key){
        if(it!=INT_MAX)
        ans+=it;
    }
    
    return ans;
}