class MinStack {
public:
    long long point;
    vector<long long> st;
    MinStack() {}
    
    void push(int val) {
        if (st.size()==0 ){
            st.push_back(val); point=val;
        }else if ( val < point ){
            st.push_back((long long)2*val - point);
            point = val;
        }else { st.push_back(val); }
    }
    
    void pop() {
        if ( st.back()<point ){
            point = 2*point-st.back();
            st.pop_back();
        }else st.pop_back();
    }
    
    int top() {
        if ( st.back()<point ) return point;
        return st.back();
    }
    
    int getMin() {
        return point;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */