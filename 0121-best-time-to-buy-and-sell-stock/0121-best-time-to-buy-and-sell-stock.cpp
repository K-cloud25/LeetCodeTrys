class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m =0, mi=INT_MAX;
        for( int n : prices){
            mi = min(mi, n);
            m = max(m, n-mi);
        }
        return m;
    }
};