class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,f=0,res=0;
        vector<int> arr(26,0);
        while( r<s.length() ){
            arr[s[r] - 'A']++;
            f=max( f, arr[s[r]-'A'] );
            while( ( r-l+1 )-f>k ){
                arr[s[l]-'A']--;
                l++;
            }
            res=max((r-l+1), res);
            r++;
        }
        return res;
    }
};