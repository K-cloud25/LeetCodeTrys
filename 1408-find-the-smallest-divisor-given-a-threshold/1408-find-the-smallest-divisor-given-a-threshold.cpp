class Solution {
public:
    int smallestDivisor(vector<int>& arr, int threshold) {

        int left = 1;
        int right = arr.size()-1;
        for( auto& i : arr){
            right = max(right, i);
        }

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(possible(arr, mid, threshold)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }

    bool possible(vector<int> &arr, int m, int k) {
        int hours = 0;
        for(int pile : arr){
            int div = pile / m;
            hours += pile/m;
            if(pile % m != 0) hours++;
        }
        return hours <= k;
    }
};