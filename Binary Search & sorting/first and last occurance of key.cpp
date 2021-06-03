#include<bits/stdc++.h>
using namespace std;

int fo = -1;
int lo = -1;
int currmid = -1;

int BSFO(int a[], int start, int end, int key){

    if(start<=end){

        int mid = (start+end)/2;
        if(a[mid]==key){
            currmid = mid;
            return BSFO(a, start, mid-1,key);
        }
        else if(a[mid]>key)
            return BSFO(a, start, mid-1,key);
        else 
            return BSFO(a,mid+1, end,key);
        }
        return currmid;
}


int BSLO(int a[], int start, int end, int key){

    if(start<=end){

        int mid = (start+end)/2;
        if(a[mid]==key){
            currmid = mid;
            return BSLO(a,mid+1,end,key);
        }
        else if(a[mid]>key)
            return BSLO(a, start, mid-1,key);
        else 
            return BSLO(a,mid+1, end,key);
        }

        return currmid;
}


int main(){

    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    fo = BSFO(a,0,n-1, key);
    lo = BSLO(a,0,n-1, key);
    cout<<fo<<endl;
    cout<<lo;
    return 0;
}