class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,res=0, r=0,f=0;
        vector<int> mp(26,0);

        while( r<s.length() ){
            mp[s[r]-'A']++;
            f=max(f, mp[s[r]-'A']);
            if((r-l+1)-f>k){
                mp[s[l]-'A']--;
                f=0;
                l++;
            }
            res=max(res,(r-l+1));
            r++;
        }

        return res;
    }
};