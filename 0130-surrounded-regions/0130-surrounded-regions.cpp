class Solution {

    int ROWS, COLS;
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

public:

    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        dfs(board);

        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                if (board[r][c] == 'O'){ board[r][c] = 'X'; }
                else if(board[r][c] == 'T'){ board[r][c] = 'O'; }
            }
        }
    }

    void dfs(vector<vector<char>>& board){
        queue<pair<int,int>> q;
        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                if ( ( r == 0 || c == 0 || r == ROWS-1 || c == COLS -1 ) && board[r][c] == 'O' ){
                    q.push({r,c});
                }
            }
        }
        while(!q.empty()){
            auto [r,c] = q.front(); q.pop();
            if ( board[r][c] == 'O' ){
                board[r][c] = 'T';
                for(auto& d : dir){
                    int nr = r + d.first, nc = c + d.second;
                    if( nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS  ){
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
};