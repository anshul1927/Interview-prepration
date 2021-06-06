// https://www.interviewbit.com/problems/rotated-sorted-array-search/

int Solution::search(const vector<int> &nums, int target) {
        int beg = 0;
        int end = nums.size()-1;
        
        while(beg<=end){    
            int mid = beg + (end-beg)/2;
            if(nums[mid]==target){
                return mid;
            }
           if(nums[beg]<=nums[mid])
            {
                if(target<=nums[mid] && target>=nums[beg])
                    end=mid-1;
                else
                    beg=mid+1;
            }
            
            else
            {
                if(target>=nums[mid] && target<=nums[end])
                   beg=mid+1;
                else
                    end=mid-1;
            }
        }
        return -1;
}
