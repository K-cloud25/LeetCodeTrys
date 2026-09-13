class Solution {
public:

    bool canEat(vector<int>& piles, int m, int h){
        long e = 0;
        for ( int p : piles){
            e += (p / m);
            if ( p % m != 0) e++;
        }
        return e <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1000000000;
        while ( low <= high ){
            int mid = low + ( high - low )/ 2;
            if ( canEat(piles, mid, h) ) high = mid - 1;
            else low = mid + 1;
        }
        return low;          
    }
};