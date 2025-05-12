class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() - 1, cnt=0;
        int curEnd=0, far=0;
        for(int i=0;i<n;i++){
            far = max( far, i+nums[i]);
            if ( i == curEnd ){
                cnt++;
                curEnd=far;
            }
        }
        return cnt;
    }
};