class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        combs(candidates, target, 0, comb, 0,res);
        return res;
    }

    void combs(vector<int>& arr, int t, int idx, vector<int> comb, int tt, vector<vector<int>>& res){
        if ( tt == t ){
            res.push_back(comb);
            return;
        }

        if ( tt>t || idx >= arr.size() ){
            return;
        }

        comb.push_back(arr[idx]);
        combs(arr, t, idx, comb, tt+arr[idx], res);
        comb.pop_back();
        combs(arr,t,idx+1, comb,tt,res);
    }

};