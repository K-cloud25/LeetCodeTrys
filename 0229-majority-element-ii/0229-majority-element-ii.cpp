class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1, num2;
        int cnt1=0, cnt2=0;
        for(int num : nums){
            if ( cnt1==0 && num2!=num ){
                cnt1=1;
                num1=num;
            }else if ( cnt2==0 && num1!=num ){
                cnt2=1;
                num2=num;
            }else if ( num1 == num ){
                cnt1++;
            }else if ( num2 == num ){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1=0, cnt2=0;
        for( int i : nums){
            if ( i == num1 ) cnt1++;
            if ( i == num2 ) cnt2++;
        }

        vector<int> res;
        if ( cnt1 > nums.size()/3 ) res.push_back(num1);
        if ( cnt2 > nums.size()/3 ) res.push_back(num2);
        return res;
    }
};