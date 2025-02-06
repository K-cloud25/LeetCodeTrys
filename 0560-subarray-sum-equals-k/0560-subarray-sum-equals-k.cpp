class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0] = 1;
        int cnt=0, preSum=0;
        for(int i=0;i<nums.size();i++){
            preSum += nums[i];
            cnt += m[preSum-k];
            m[preSum] += 1;
        }

        return cnt;
    }
};