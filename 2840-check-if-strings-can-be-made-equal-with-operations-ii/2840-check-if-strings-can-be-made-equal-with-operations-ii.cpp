class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        string s1e="", s1o="", s2e="", s2o="";
        for(int i=0;i<n;i++){
            if(i%2==0){
                s1e+=s1[i]; s2e+=s2[i];
            }else{
                s1o+=s1[i]; s2o+=s2[i];
            }
        }
        sort(s1e.begin(),s1e.end());
        sort(s2e.begin(),s2e.end());
        sort(s1o.begin(),s1o.end());
        sort(s2o.begin(),s2o.end());

        return (s1e==s2e && s1o==s2o);

    }
};