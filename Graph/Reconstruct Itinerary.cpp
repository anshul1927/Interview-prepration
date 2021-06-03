// lc 332
// https://leetcode.com/problems/reconstruct-itinerary/

// I used create graph in multiset of unordered_map for access lexiographical order of nodes.
// multiset stored vertices in order format.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string, multiset<string>> adj;
        
        vector<string> ans;
        
        
        for(auto el: tickets){
            adj[el[0]].insert(el[1]);
        }
        
        stack<string> s;
        s.push("JFK");
        while(!s.empty()){
            
            string src = s.top();
            
            if(adj[src].size()==0){
                ans.push_back(src);
                s.pop();
            }
            else{
                auto dest = adj[src].begin();
                s.push(*dest);
                adj[src].erase(dest);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};