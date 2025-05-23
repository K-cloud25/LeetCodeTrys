class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if( i>0 && nums[i] == nums[i-1] ) continue;
            int j=i+1;
            int k=n-1;
            while( j < k ){
                int total = nums[i] + nums[j] + nums[k];
                if ( total < 0 ){
                    j++;
                }else if ( total > 0 ){
                    k--;
                }else{
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while ( nums[j] == nums[j-1] && j<k ){
                        j++;
                    }
                } 
            }
        }
        return res;
    }
};