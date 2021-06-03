// https://leetcode.com/problems/word-ladder/
// lc 127

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string A, string B, vector<string>& C) {
    unordered_set<string> set_of_string;
    
    bool isPresent = false;
    
    for(auto s: C){
        if(B.compare(s)==0){
            isPresent = true;
            cout<<"true"<<endl;
        }
        set_of_string.insert(s);
    }
    
    if(isPresent==false){
        return 0;
    }
    
    
    queue<string> q;
    q.push(A);
    
    int depth = 0;
    
    while(!q.empty()){
        depth+=1;
        int queue_size = q.size();
        
        while(queue_size--){
            string curr = q.front();
            q.pop();
            
            for(int i=0; i<curr.size(); i++){
                string temp = curr;
                for(char ch='a'; ch<='z'; ch++){
                    temp[i] = ch;
                    
                    if(curr.compare(temp)==0){
                        continue;
                    }else if( temp.compare(B)==0){
                        return depth+1;
                    }else if(set_of_string.find(temp)!=set_of_string.end()){
                        q.push(temp);
                        set_of_string.erase(temp);
                    }
                }
            }
        }
    }
    return 0;
    }
};