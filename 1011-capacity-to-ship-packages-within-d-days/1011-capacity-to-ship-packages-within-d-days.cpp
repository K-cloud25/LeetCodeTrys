class Solution {
public:

    int cal(vector<int>&we, int days, int maxW){
        int d = 1;
        int sum = 0;
        for ( int w : we){
            if ( sum + w > maxW) {
                d++;
                sum = w;
            } else sum += w;
        }
        return d <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while ( left <= right ){
            int mid = left + ( right - left ) / 2;
            if ( cal(weights, days, mid) ) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};