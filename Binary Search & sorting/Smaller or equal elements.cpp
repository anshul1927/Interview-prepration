// https://www.interviewbit.com/problems/smaller-or-equal-elements/

#include<bits/stdc++.h>
using namespace std;

int Solution::solve(vector<int> &A, int B) {
    
    int it = upper_bound(A.begin(), A.end(), B)-A.begin();
    
    if(A[it]==B){
        return it+1;
    }
    return it;
}