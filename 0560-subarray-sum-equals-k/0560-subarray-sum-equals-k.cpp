class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0]=1;
        int cnt=0, preSum=0;
        for(int num: nums){
            preSum+=num;
            cnt+=m[preSum-k];
            m[preSum]+=1;
        }
        return cnt;
    }
};