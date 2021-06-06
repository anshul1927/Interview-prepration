//https://www.interviewbit.com/problems/woodcutting-made-easy/

int isValid(vector<int> &A, int B, int mid){
    
    int currH = 0;
    int tree = 1;
    for(auto it: A){
        if( currH + max(0,it-mid)>=B){
            return true;
        }
        else{
            currH+= max(0, it-mid);
        }
    }
    return false;
}
 
int Solution::solve(vector<int> &A, int B) {
    
    
    int start = *min_element(A.begin(), A.end());
    int end = *max_element(A.begin(), A.end());;
    int ans=0;
    
    while(start<=end){
        
        int mid = (start+end)>>1;
        if(isValid(A, B, mid)){
            ans = max(ans, mid);
            start =mid+1;
        }else{
            end = mid-1;
        }
    }
    
    return ans;
    
}