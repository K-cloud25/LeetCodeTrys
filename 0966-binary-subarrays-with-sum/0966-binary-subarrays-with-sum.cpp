class Solution {
public:
    
    int count(vector<int>& nums, int goal){

        if ( goal<0) return 0;
        int left=0, right=0, cnt=0, sum=0;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            cnt=cnt+(right-left+1);
            right++;
        }
        return cnt;

    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return count(nums, goal) - count(nums, goal-1);
    }
};