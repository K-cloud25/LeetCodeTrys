class Solution {

    void subset(vector<int>& nums, int index, vector<int> out, vector<vector<int>>& ans){
        if ( index >= nums.size() ){
            ans.push_back(out);
            return;
        } 

        subset(nums, index+1, out, ans);

        out.push_back(nums[index]);
        subset(nums, index+1, out, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        int index=0;
        subset(nums, index, out, res);
        return res;
    }
};