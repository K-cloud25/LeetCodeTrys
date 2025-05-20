class Solution {
public:

    int firstMissingPositive(vector<int>& nums) {
        auto config = [](int i){ return i <= 0; };
        nums.erase( remove_if ( nums.begin(), nums.end(), config ), nums.end() );
        int n=nums.size(), k=0;
        for(int i=0;i<n;i++){
            k = abs(nums[i]);
            if ( k<=n && nums[k-1]>0 ){
                nums[k-1] = 0 - nums[k-1];
            }
        }

        for(int i=0;i<n;i++){
            if ( nums[i] > 0 ) return i+1;
        }

        return n+1;
    }
};