// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// 329

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int dp[201][200+1];
    int n,m,ans;
    
    
    int dfs(vector<vector<int>>& matrix, int i, int j, int preValue){
        
        if(i<0 || j<0 || i>=m || j>=n || matrix[i][j]<=preValue) return 0;
        
        if(dp[i][j]) return dp[i][j];
        
        
        return dp[i][j] = 1 + max( {dfs(matrix, i+1, j, matrix[i][j]), dfs(matrix, i, j+1, matrix[i][j]),
                                 dfs(matrix, i-1, j, matrix[i][j]),dfs(matrix, i, j-1, matrix[i][j])});
        
    }
        
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, dfs(matrix, i, j, -1));
            }
        }
        
        return ans;
    }
};