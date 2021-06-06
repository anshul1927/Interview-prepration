// https://www.interviewbit.com/problems/square-root-of-integer/

#include<bits/stdc++.h>
using namespace std;

int sqrt(int A) {
    
    
   
    long long int start = 0;
    long long int end = A;
    
    while(start<=end){
        
        long long int mid = start + (end-start)/2;
        
        if(mid*mid<=A){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    
    return (int)end;
}
