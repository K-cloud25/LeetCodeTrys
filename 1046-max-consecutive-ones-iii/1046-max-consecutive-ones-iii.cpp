class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r=0, le=0, res=0;
        while(r<nums.size()){

            if ( nums[r] == 1 ){
                r++;
                le++;
            }else{
                if( k > 0 ){
                    le++;
                    r++;
                    k--;
                }else{
                    while( nums[l] == 1 ){
                        l++;
                        le--;
                    }
                    l++;
                    le--;
                    k++;
                }
            }

            res=max(res,le);
        }

        return res;
    }
};