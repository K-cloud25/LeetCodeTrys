class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for( string s : strs ){
            string word =s;
            sort(word.begin(), word.end());
            mp[word].push_back(s);
        }
        vector<vector<string>> n;
        for(auto s : mp){
            n.push_back(s.second);
        }
        return n;
    }
};