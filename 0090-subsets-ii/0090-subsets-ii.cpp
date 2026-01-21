class Solution {
public:

    void backtrack(vector<int> comb, vector<vector<int>>& res, vector<int> nums, int i){
        if( i==nums.size() ){
            res.push_back(comb);
            return;
        }

        comb.push_back(nums[i]);
        backtrack(comb, res, nums, i+1);
        comb.pop_back();
        while( i+1< nums.size()  && nums[i] == nums[i+1] ) i++;
        backtrack(comb,res,nums,i+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<int> comb;
      vector<vector<int>> res;
      sort(nums.begin(), nums.end());
      backtrack(comb, res, nums, 0);
      return res;  
    }
};