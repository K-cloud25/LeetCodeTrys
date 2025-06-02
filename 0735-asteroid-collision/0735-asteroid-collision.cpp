class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int a : asteroids){
            if ( a>0 ) { st.push(a); }
            else{
                while (!st.empty() && st.top() > 0 && st.top() < -a) {
                    st.pop();
                }

                if (st.empty() || st.top() < 0) {
                    st.push(a);
                }

                if (!st.empty() && st.top() == -a) {
                    st.pop();
                }

            }

        } 
        vector<int> arr;
        while(!st.empty()) {arr.push_back(st.top()); st.pop();}
        reverse(arr.begin(), arr.end());
        return arr;
    }
};