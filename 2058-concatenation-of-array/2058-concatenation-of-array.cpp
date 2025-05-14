class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> num = nums;
        for(int& n : nums){
            num.push_back(n);
        }
        return num;
    }
};