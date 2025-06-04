class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> r[9], c[9], b[9];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if ( board[i][j] == '.' ) continue;
                char val = board[i][j];
                int index= ( i / 3 ) * 3 + ( j / 3 );

                if ( r[i].count(val) || c[j].count(val) || b[index].count(val) )
                    return false;
                
                r[i].insert(val);
                c[j].insert(val);
                b[index].insert(val);

            }
        }

        return true;
    }
};