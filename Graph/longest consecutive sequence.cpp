// https://leetcode.com/problems/longest-consecutive-sequence/
// lc 128

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s;
        for(auto el:nums) s.insert(el);
        
        int longestAns = 0;
        
        for(auto el: nums){
            
            if(!s.count(el-1)){
                int currentNum = el+1;
                
                while(s.count(currentNum)){
                    currentNum+=1;
                }
                
                longestAns = max(longestAns, currentNum-el);
            }
        }
        
        return longestAns;
    }
};