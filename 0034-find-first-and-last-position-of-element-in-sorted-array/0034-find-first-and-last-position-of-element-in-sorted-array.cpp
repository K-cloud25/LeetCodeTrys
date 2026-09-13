class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = -1, right = -1;
        // left 
        int low = 0, high = nums.size()-1;
        int t = -1;
        while(low<=high){
            int mid = low + ( high - low ) /2;
            if ( nums[mid] == target ) {
                t = mid;
                high = mid - 1;
            } else if ( nums[mid] > target ) high = mid - 1;
            else low = mid + 1; 
        }

        left=t;
        low = 0, high = nums.size() -1;
        t=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if ( nums[mid] == target ){
                t = mid;
                low = mid + 1;
            }
            else if ( nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        right = t;

        return {left, right};
    }
};