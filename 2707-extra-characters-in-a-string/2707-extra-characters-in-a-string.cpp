class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;
    TrieNode(){ 
        for(int i=0;i<26;i++) children[i] = nullptr;
        endOfWord = false;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){root = new TrieNode();}

    void addWord(string word){
        TrieNode* cur = root;
        for(char c : word){
            int i = c - 'a';
            if ( cur->children[i] == nullptr ){
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->endOfWord = true;
    }
};

class Solution {
public:

    int minExtraChar(string s, vector<string>& dictionary) {
    Trie tr;
        for(const string& word : dictionary){
            tr.addWord(word);
        }
        int n = s.size();
        vector<int> dp(n+1);
        for(int i=n-1;i>=0;--i){
            dp[i] = 1 + dp[i+1];
            TrieNode* curr = tr.root;
            for(int j=i;j<n;++j){
                if ( !curr->children[s[j] - 'a'] ) break;
                curr = curr->children[s[j]-'a'];
                if ( curr->endOfWord ){
                    dp[i] = min(dp[i],dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};