// https://leetcode.com/problems/perfect-squares/
// lc279

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numSquares(int n) {
        if (n==0 || n==1)
            return n;
        
        
        queue<int> q;
        q.push(0);
        
        int level = 0;
        unordered_set<int> s;
        s.insert(0);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0; i<size;i++){
                
                int curr = q.front();
                q.pop();
                
                for(int j=1; curr + j*j<=n; j++){
                    
                    int temp = curr + j*j;
                    if(temp==n)
                        return level+1;
                    
                    if(s.count(temp)==0){
                        s.insert(temp);
                        q.push(temp);
                    }
                }
            }
            level++;
        }
        
        return 0;
    }
};P