class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";
        int n1 = word1.length(), n2=word2.length();
        int j=0, k=0;
        while( j<n1 && k<n2 ){
            s+=word1[j++];
            s+=word2[k++];
        }
        while( j<n1 ) s+=word1[j++];
        while( k<n2 ) s+=word2[k++];
        return s;
    }
};