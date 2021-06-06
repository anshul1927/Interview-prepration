// https://www.interviewbit.com/problems/matrix-search/


int Solution::searchMatrix(vector<vector<int> > &matrix, int target) {
    
    int r = matrix.size();
        int c = matrix[0].size();
        int i = 0;
        int j = c-1;
        
        while(i>=0 && i<r && j>=0 && j<c){
            if(matrix[i][j]==target){
                return 1;
            }else if(matrix[i][j]>target){
                j--;
            }else{
                i++;
            }
        }
        return 0;
}
