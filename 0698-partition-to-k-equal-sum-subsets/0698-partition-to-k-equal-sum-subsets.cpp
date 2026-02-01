class Solution {
public:
    bool helper(vector<int>& nums , vector<int>& groups , int target , int idx){
        if(idx == nums.size()) return true;
        for(int i = 1 ; i<groups.size() ; i++){
            
            if(i > 1 && groups[i-1] == groups[i]) continue;

            if(nums[idx] + groups[i] > target)continue;
            groups[i] += nums[idx];
            if(helper(nums , groups , target , idx + 1)) return true;
            groups[i] -= nums[idx];

            if(nums[i] == 0)break;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k == 1)return true;
        if(k > nums.size()) return false;

        sort(nums.begin() , nums.end());
        reverse(nums.begin() , nums.end());
        vector<int> groups(k+1 , 0);

        int target = 0;
        for(const auto val : nums)target += val;
        if(target % k || nums[0] > target)return false;

        target /= k;
        return helper(nums , groups , target , 0);
    }
};