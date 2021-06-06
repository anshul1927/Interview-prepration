// https://www.interviewbit.com/problems/search-in-bitonic-array/

int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    
    int start = 0;
        int end = n-1;
        int peak;
        int bp;
        while(start<=end){
            peak = start + (end-start)/2;
                if(A[peak]>A[peak-1] && A[peak]>A[peak+1]){
                    break;
                }else if(A[peak]>A[peak-1]){
                    start = peak+1;
                }
                else{
                    end = peak-1;
                }
        }
        
       
 
        
        bp = peak;
        if(A[bp]==B){
            return bp;
        }
        if(A[bp]<B){
            return -1;
        }
        
        int s = 0;
        int e = bp;
        while(s<=e){
            peak = s + (e-s)/2;
            
            if(A[peak]==B){
                return peak;
            }else if(A[peak]<B){
                s = peak+1;
            }else {
                e = peak-1;
            }
        }
        
        s = peak+1;
        e = n-1;
            
        while(s<=e){
            peak = s + (e-s)/2;
            if(A[peak]==B) return peak;
            else if(A[peak]<B) e = peak-1;
            else s = peak+1;
        }
        return -1;
}