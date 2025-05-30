class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if ( c==')' || c=='}' || c==']' ){
                if ( st.empty() ) return false;
                if ( c==')' && st.top()!='(' ){
                    return false;
                }
                else if ( c=='}' && st.top()!='{' ){
                    return false;
                }else if ( c==']' && st.top()!='[' ){
                    return false;
                }
                st.pop();
            }else{
                st.push(c);
            }
        }
        return st.empty();
    }
};