// https://www.interviewbit.com/problems/search-for-a-range/

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    
    if(binary_search(A.begin(), A.end(), B)==false){
        return vector<int>{-1,-1};
    }
    int l = lower_bound(A.begin(), A.end(), B) - A.begin();
    int r = upper_bound(A.begin(), A.end(), B) - A.begin();
    
    return vector<int> {l,r-1};
}