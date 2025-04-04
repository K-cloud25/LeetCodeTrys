class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1,suffix=1;
        int n=nums.size();
        int m=nums[0];
        for(int i=0;i<nums.size();i++){
            if(prefix==0)prefix=1;
            if(suffix==0)suffix=1;
            prefix=prefix*nums[i];
            suffix=suffix*nums[n-i-1];
            m = max(m, max(suffix,prefix));
        }
        return m;
    }
};