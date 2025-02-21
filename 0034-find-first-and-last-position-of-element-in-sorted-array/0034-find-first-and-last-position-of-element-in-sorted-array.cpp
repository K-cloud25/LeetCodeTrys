class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};

        int left = 0;
        int right = nums.size()-1;

        while(left<=right){
            int mid = left + (right-left)/2;
            if ( nums[mid] <= target){
                if ( nums[mid] == target)
                    ans[1] = mid;
                left=mid+1;
            }
            if ( nums[mid] > target) right = mid-1;
        }
        left=0;right=nums.size()-1;

        while(left<=right){
            int mid = left + (right - left)/2;
            if ( nums[mid] < target) left = mid + 1;
            if ( nums[mid] >= target ){
                if ( nums[mid] == target) 
                    ans[0] = mid;
                right=mid-1;
            } 
        }

        return ans;
    }
};