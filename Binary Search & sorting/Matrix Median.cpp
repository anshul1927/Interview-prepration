// https://www.interviewbit.com/problems/matrix-median/

int countSmallerthanMid(vector<int> &row, int mid){
    
    int l=0;
    int r = row.size()-1;
    
    while(l<=r){
        int m = (l+r)>>1;
        
        if(row[m]<=mid){
            l = m+1;
        }else{
            r = m-1;
        }
    }
    return l;
}
 
 
int Solution::findMedian(vector<vector<int> > &A) {
    
    int start = 1;
    int end = 1e9;
    
    int n = A.size();
    int m = A[0].size();
    
    while(start<=end){
        int mid = (start + end)>>1;
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            cnt += countSmallerthanMid(A[i], mid);
        }
        
        if(cnt<= (n*m)/2){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return start;
}