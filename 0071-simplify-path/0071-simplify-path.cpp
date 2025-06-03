class Solution {
private:
    vector<string> st;

public:
    string simplifyPath(string path) {
        vector<string> components;
        stringstream ss(path);
        string comp;
        while (getline(ss, comp, '/')) {
            if (comp == "" || comp == ".") {
                continue;
            }

            if (comp == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(comp);
            }
        }
        stringstream simPath;
        for(const string &s : st){
            simPath<<"/"<<s;
        }

        return simPath.str().empty()?"/":simPath.str();
    }
};