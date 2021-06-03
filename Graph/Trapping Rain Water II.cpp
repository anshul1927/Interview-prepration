// https://leetcode.com/problems/trapping-rain-water-ii/
// lc 407

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int r = heightMap.size();
        int c = heightMap[0].size();
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        
        vector<vector<int>> visited(r, vector<int>(c, false));
        
        for(int i=0; i<r;i++){
            pq.push({heightMap[i][0], {i,0}});
            pq.push({heightMap[i][c-1], {i,c-1}});
            visited[i][0] = true;
            visited[i][c-1] = true;
        }
        
        for(int i=1; i<c-1; i++){
            pq.push({heightMap[0][i], {0,i}});
            pq.push({heightMap[r-1][i], {r-1, i}});
            visited[0][i] = visited[r-1][i] = true;
        }
        
        int ans = 0;
        
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        
        while(!pq.empty()){
            int r1 = pq.top().second.first;
            int c1 = pq.top().second.second;
            int currWt = pq.top().first;
            pq.pop();
            for(int i=0; i<4; i++){
                
                int ii = r1+dx[i];
                int jj = c1+dy[i];
                
                if(ii<0 || ii>=r || jj<0 || jj>=c || visited[ii][jj]==true){
                    continue;
                }
                
                ans += max(0, currWt-heightMap[ii][jj]);
                pq.push({max(currWt, heightMap[ii][jj]), {ii,jj}});
                visited[ii][jj] = true;
            }
            
        }
        return ans;
    }
};