class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=0, mi=INT_MAX;
        for(int i : prices){
            mi = min(mi, i);
            m = max(m, i-mi);
        }
        return m;
    }
};