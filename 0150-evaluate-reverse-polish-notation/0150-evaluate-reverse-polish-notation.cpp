class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens){
            if ( s=="+" ){
                int o1 = st.top(); st.pop();
                int o2 = st.top(); st.pop();
                st.push(o2+o1);
            } else if ( s=="-" ){
                int o1 = st.top(); st.pop();
                int o2 = st.top(); st.pop();
                st.push(o2-o1);
            }else if ( s=="*" ){
                int o1 = st.top(); st.pop();
                int o2 = st.top(); st.pop();
                st.push(o2*o1);
            }else if ( s=="/" ){
                int o1 = st.top(); st.pop();
                int o2 = st.top(); st.pop();
                st.push(o2/o1);
            }else st.push(stoi(s));
        }
        return st.top();
    }
};