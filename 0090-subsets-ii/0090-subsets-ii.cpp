class Solution {
public:

    void backtrack(vector<int>& nums, vector<int> comb, vector<vector<int>>& res, int i){
        if (i == nums.size()) {
            res.push_back(comb);
            return;
        }

        comb.push_back(nums[i]);
        backtrack( nums, comb, res, i+1);
        comb.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        backtrack( nums, comb, res, i+1);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> comb;
        sort(nums.begin(), nums.end());
        backtrack(nums, comb, res, 0);
        return res;
    }
};