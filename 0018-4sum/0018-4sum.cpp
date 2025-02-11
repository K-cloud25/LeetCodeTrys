class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
vector<vector<int>> th;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i<n;i++){

            if ( i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            for(int l = i+1; l<n; l++){

                if ( l > i+1 && nums[l] == nums[l-1]){
                    continue;
                }

                int j = l+1;
                int k = n - 1;

                while( j < k ){

                    long long total = nums[i];
                    total +=nums[j];
                    total += nums[k];
                    total += nums[l];

                    if ( total > target ){
                        k-=1;
                    }else if(total < target){
                        j+=1;
                    }else{
                        th.push_back({nums[i], nums[j], nums[k], nums[l]});
                        j+=1;
                        while(nums[j] == nums[j-1] && j < k){
                            j+=1;
                        }
                    }

                }

            }
        }

        return th;
    }
};