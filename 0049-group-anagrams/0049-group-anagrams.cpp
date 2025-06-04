class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> st;
        for( string s : strs ){
            string key = s;
            sort(s.begin(), s.end());
            map[s].push_back(key);
        }      
        for(auto s: map){
            st.push_back(s.second);
        }
        return st;
    }
};