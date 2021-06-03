#include<bits/stdc++.h>
using namespace std;



int BS(int a[], int start, int end, int key){

    if(start<=end){

        int mid = (start+end)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]>key)
            return BS(a, start, mid-1,key);
        else 
            return BS(a,mid+1, end,key);
        }
        return -1;
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
//    cout<<" Key element is present at "<<BS(a,0,n-1, key)<<" in the vector \n";
    cout<<binary_search(a,a+n,key)<<endl;

    // for index 
    cout<<"#";
    auto it = lower_bound(a, a+n, key);
    cout<<it-a<<endl;

    auto it1 = upper_bound(a, a+n, key);
    cout<<it1-a<<endl;

    cout<<"total no of occurance of key is "<<it1-it<<endl;
    return 0;
}