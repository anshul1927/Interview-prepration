// https://www.interviewbit.com/problems/allocate-books/

bool isValid(vector<int>& A, int B, int mid){
    int n = A.size();
    int student = 1;
    int sum = 0;
    for(int i=0;i<n; i++){
        sum += A[i];
        if(sum>mid){
            student++;
            sum = A[i];
        }
        if(student>B){
            return false;
        }
    }
    
    return true;
}

int Solution::books(vector<int> &A, int B) {
    
    if(A.size()<B){
        return -1;
    }
    
    int sum = 0;
    int m = INT_MIN;
    
    for(auto it: A){
        m = max(m, it);
        sum+=it;
    }
    
    int start = m;
    int end = sum;
    int res = -1;
    while(start<=end){
        int mid = start + (end-start)/2;
        
        if(isValid(A, B, mid)==true){
            res = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return res;
}
