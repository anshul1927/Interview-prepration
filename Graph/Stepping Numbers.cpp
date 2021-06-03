// https://www.interviewbit.com/problems/stepping-numbers/

#include <bits/stdc++.h>
using namespace std;


void dfs(int num, int A, int B, vector<int>& ans){
    if(num>B){
        return;
    }
    
    if(num>=A){
        return ans.push_back(num);
    }
    
    int lastdigit = num%10;
    
    if(lastdigit-1>=0)
        dfs(num*10 + lastdigit-1, A, B, ans);
    
    if(lastdigit+1<=9){
        dfs(num*10+lastdigit+1, A, B, ans);
    }
    
    
}

vector<int> Solution::stepnum(int A, int B) {
    
    vector<int> ans;
    
    if(A<=0 && high>=0) return ans.push_back(0);
    
    for(int i=1; i<=9; i++){
        dfs(i, A, B, ans);
    }
    
    sort(ans.begin(), ans.end());
    
}
