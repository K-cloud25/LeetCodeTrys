class Solution {
public:

    bool areVectorEqual(vector<int> a, vector<int> b) {
        for ( int i=0;i<26;i++ ){
            if ( a[i]!=b[i] ) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if ( s1.length() > s2.length() ) return false;
        vector<int> map1(26, 0);
        vector<int> map2(26, 0);
        for( char c : s1 ) map1[c-'a']++;
        int i=0,j=0;
        while ( j < s2.length() ) {

            map2[s2[j]-'a']++;
            
            if ( j-i+1==s1.size() ){ if ( areVectorEqual(map1,map2)) return true; }

            if ( j-i+1<s1.size() ) j++;
            else{
                map2[s2[i]-'a']--; i++; j++;
            }
        }
        return false;
    }
};