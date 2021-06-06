// https://www.interviewbit.com/problems/median-of-array/

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    if(A.size()>B.size()) return findMedianSortedArrays(B, A);
    int n1 = A.size();
    int n2 = B.size();
    
    int start = 0;
    int end = n1;
    
    while(start<=end){
        
        int cut1 = (start + end)>>1;
        
        int cut2 = (n1+n2+1)/2 - cut1;
        
        int l1 = cut1==0? INT_MIN:A[cut1-1];
        int l2 = cut2==0? INT_MIN:B[cut2-1];
        int r1 = cut1==n1? INT_MAX:A[cut1];
        int r2 = cut2==n2? INT_MAX:B[cut2];
        
        if(l1<=r2 && l2<=r1){
            if((n1+n2)%2==0){
                return (max(l1,l2)+min(r1,r2))/2.0;
            }else{
                return max(l1,l2);
            }
        }else if(l1>r2){
            end = cut1-1;
        }else{
            start = cut1+1;
        }
    }
    return 0.0;
}
