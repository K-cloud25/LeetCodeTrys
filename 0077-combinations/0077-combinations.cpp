class Solution {

    void back(int start, vector<int> com, vector<vector<int>>& res, int k, int n){
        if ( com.size() == k ){
            res.push_back(com);
            return;
        }
        for ( int i=start; i<=n;i++){
            com.push_back(i);
            back(i+1,com,res,k,n);
            com.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        back(1, comb, res, k, n);
        return res;
    }
};