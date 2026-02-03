class Solution {
public:
    int col=0, uDia=0, dDia=0;
    vector<string> board;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        board.resize(n, string(n,'.'));
        backtrack(0,n);
        return res;
    }

    void backtrack(int r, int n){
        if ( r==n ){
            res.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if ( (col & (1<<i)) || (uDia & (1 << (r+i))) || (dDia & ( 1 << ( r - i + n))) ){
                continue;
            }

            col ^= ( 1 << i );
            uDia ^= ( 1 << ( r + i ) );
            dDia ^= ( 1 << (r - i + n ));
            board[r][i] = 'Q';

            backtrack(r+1, n);

            col ^= ( 1 << i );
            uDia ^= ( 1 << ( r + i ) );
            dDia ^= ( 1 << (r - i + n ));
            board[r][i] = '.';
        }
    }
};