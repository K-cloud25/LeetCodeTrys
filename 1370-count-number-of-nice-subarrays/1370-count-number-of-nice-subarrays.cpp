class Solution {
public:

    int count(vector<int>&nums, int k){
        if(k<0) return 0;
        int l=0,r=0,res=0,cnt=0;
        while(r<nums.size()){
            cnt+=nums[r];
            while( cnt>k ){
                cnt-=nums[l];
                l++;
            }
            res+=r-l+1;
            r++;
        }

        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]%2;
        }
        return count(nums,k) - count(nums,k-1);
    }
};