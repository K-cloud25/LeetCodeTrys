class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0; 
        int profit=0;
        int n = prices.size();
        while ( i < n-1 ){
            if ( prices[i+1] > prices[i] )
                profit += prices[i+1]-prices[i];
            i++;
        }
        return profit;
    }
};