class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = -1, co = 0;
        for(int i : nums){
            if ( co <= 0 ){
                c=i;
            }
            if ( i == c ){
                co++;
            }else{
                co--;
            }
        }
        return c;
    }
};