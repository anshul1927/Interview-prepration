// https://www.interviewbit.com/problems/delete-edge/

#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> mp;
long long int res;
vector<bool> visit;
const long long int mod = 1e9+7;



long long int dfs(int src, vector<int>& A, long long int s){
    
    
    visit[src] = true;
    long long int sum = 0;
    
    for(auto neigh: mp[src]){
        if(visit[neigh]){
            continue;
        }
        
        int x = dfs(neigh, A, s);
        res = max( res%mod, (long long int )((x%mod)*((s-x)%mod)%mod));
        sum = (sum%mod + x%mod)%mod;
    }
    
    visit[src] = false;
    
    return (sum%mod + A[src-1]%mod)%mod;
}
int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    
    visit.clear();
    mp.clear();
    
    for(auto x:B){
        mp[x[0]].push_back(x[1]);
        mp[x[1]].push_back(x[0]);
    }
    
    res = 0;
    long long int s = 0;
    
    for(int e: A) s = (s%mod + e%mod)%mod;
    
    visit.resize(A.size()+1, false);
    
    dfs(1,A,s);
    
    return res%mod;
    
}
