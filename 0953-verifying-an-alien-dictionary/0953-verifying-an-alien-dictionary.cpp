class Solution {
public:
    bool isAlienSorted(vector<string>& words, string orders) {
        int order[26] = {0};
        for (int i = 0; i < orders.size(); ++i)
            order[orders[i] - 'a'] = i;

        for(int i =0;i<words.size()-1;++i){
            string c1 = words[i];
            string c2 = words[i+1];
            int j = 0;
            for(; j<c1.size(); ++j){
                if( j == c2.size() ) return false;
                if ( c1[j] != c2[j] ){
                    if ( order[c1[j] - 'a'] > order[c2[j] - 'a'] ) return false;
                    break;
                }
            }
        } 
        return true;
    }
};