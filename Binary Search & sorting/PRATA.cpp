// we have to make n prata in minimum no of time and it is given that total we have
// L number of cooks and each one of having rank associated.
// rank means :- if 1 cook have ranke R than he will make 1st prata in 1R min 
// 2nd prata in 2R min 3rd prata in 3R min ... 
// we have to find minimum no of time to make prata.

#include<bits/stdc++.h>
using namespace std;




bool isValid(int p, int cook, vector<int>& rank, int mid){

    int totalPrata = 0;
    for(auto it: rank){
        int currTime = 0;
        int i = 1;
        int currPrata = 0;
        while(currTime<=mid){
            currTime += it*i;
            i++;
            if(currTime>mid){
                break;
            }
            currPrata++;
        }
        totalPrata+=currPrata;
    }
    if(totalPrata>=p){
        return true;
    }
    return false;
}




int main(){

    int p;
    cin>>p;

    int cook;
    cin>>cook;

    vector<int> rank(cook);
    for(int i=0; i<cook; i++){
        cin>>rank[i];
    }

    int minimum_rank = *min_element(rank.begin(), rank.end());

    int start = 0;
    int end = (p*(p+1)/2)*minimum_rank;
    int ans = 0;
    while(start<=end){
        int mid = start + (end-start)/2;


        if(isValid(p, cook, rank, mid)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    cout<<endl<<ans<<endl;
    return 0;
}