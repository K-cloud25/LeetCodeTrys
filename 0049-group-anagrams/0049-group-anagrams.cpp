class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for ( string s: strs ){
            string c = s;
            sort(s.begin(), s.end());
            map[s].push_back(c);
        }
        vector<vector<string>> res;
        for( const auto& pair : map ){
            res.push_back(pair.second);
        }
        return res;
    }
};