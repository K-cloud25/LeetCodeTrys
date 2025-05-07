class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a=0, b=0;
        for(auto& it: bills){
            if ( it == 5 ) a++;
            if ( it == 10 ) {
                b++;
                if ( a<1 ) return false;
                a--;
            }
            if ( it == 20 ) {

                if ( b == 0 ){
                    if( a<3) return false;
                    a-=3;

                }else{
                    if ( a<1 ) return false;
                    a--;b--;
                }

            }
        }
        return true;
    }
};