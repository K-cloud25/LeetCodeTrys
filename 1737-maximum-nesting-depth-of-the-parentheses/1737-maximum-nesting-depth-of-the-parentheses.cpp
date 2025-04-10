class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int m=0;
        for ( char&c: s ){
            if ( c == '('){
                count++;
                m = max(count , m);
            }
            if ( c == ')'){
                count--;
            }
        }
        return m;
    }
};