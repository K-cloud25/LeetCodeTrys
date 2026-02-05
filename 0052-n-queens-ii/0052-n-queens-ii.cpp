class Solution {
public:
    int col = 0, uDia = 0, lDia = 0;
    int totalNQueens(int n) {
        int res = 0;
        backtrack(0, n, res);
        return res;
    }

    void backtrack(int row, int n, int& res){
        if ( row == n ){
            res++;
            return;
        }

        for (int i=0; i<n;i++){
            if ( (col & (1 << i)) || (uDia & (1 << row+i)) || (lDia & ( 1 << row-i+n))) continue;

            col ^= 1 << i;
            uDia ^= 1 << ( row + i);
            lDia ^= 1 << ( row - i + n);
            backtrack(row+1, n, res);
            col ^= 1 << i;
            uDia ^= 1 << ( row + i);
            lDia ^= 1 << ( row - i + n);
        }
    }
};