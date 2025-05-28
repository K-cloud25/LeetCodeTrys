class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        for( int i=1;i<n;i++) nums[i] = nums[i-1] + nums[i];
        if ( nums[n-1] < target ) return 0;
        int l = INT_MAX;
        int i=0, j=0;
        
        while( j < n){
            if ( nums[j] >= target ) l=min(l, j+1);
            if ( nums[j] - nums[i] >= target ){
                l = min(l, j-i);
                i++;
            }else j++;
        }

        return l;
    }
};