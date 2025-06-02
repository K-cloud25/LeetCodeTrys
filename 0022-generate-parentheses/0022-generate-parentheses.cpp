class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, res, 0, 0, "");
        return res;
    }

    void dfs( int n, vector<string>&res, int openB, int closeB, string t){
        if ( openB==closeB && openB+closeB==n*2 ){
            res.push_back(t);
            return;
        }

        if ( openB < n ){
            dfs(n,res,openB+1,closeB,t+"(");
        }

        if ( closeB<openB){
            dfs(n,res,openB,closeB+1,t+")");
        }
    }
};