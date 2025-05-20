class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=INT_MIN, num2=INT_MIN;
        int cnt1=0, cnt2=0;
        for(int num : nums){
            if ( cnt1==0 && num2!=num ){
                cnt1=1;
                num1=num;
            }else if ( cnt2==0 && num1!=num ){
                cnt2=1;
                num2=num;
            }else if ( num == num1 ){
                cnt1++;
            }else if ( num == num2 ){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1=0;cnt2=0;
        int mini = (int)nums.size()/3 + 1;
        for(int num : nums){
            if ( num == num1 ) cnt1++;
            if ( num == num2 ) cnt2++;
        }
        vector<int>ls;
        if( cnt1 >= mini ) ls.push_back(num1);
        if( cnt2 >= mini ) ls.push_back(num2);
        return ls;
    }
};