class Solution {
public:
    int rob(vector<int>& nums) {
        int rb1 =0, rb2 = 0;
        for(int i : nums){
            int temp = max( i + rb1, rb2 );
            rb1 = rb2;
            rb2 = temp;
        }
        return rb2;
    }
};