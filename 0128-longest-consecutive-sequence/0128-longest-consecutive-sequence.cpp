class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if ( nums.size() == 0 ) return 0;
        sort(nums.begin(), nums.end());
        int cnt=1, prevNum=INT_MIN, ans=0;
        for(int i=0;i<nums.size();i++){
            if( prevNum == nums[i]-1 ){
                cnt++;
                prevNum++;
            }else if ( nums[i] > prevNum ){
                prevNum = nums[i];
                cnt=1;
            }
            ans=max(cnt, ans);

        }

        return ans;
    }
};