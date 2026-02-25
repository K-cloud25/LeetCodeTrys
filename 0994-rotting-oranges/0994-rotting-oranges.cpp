class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROW = grid.size(); int COL = grid[0].size();
        int time = 0, fresh = 0;
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(grid[i][j] == 1) fresh++;
            }
        }
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(fresh>0){
            int flag = false;
            for(int i =0;i<ROW;i++){
                for(int j=0;j<COL;j++){
                    if ( grid[i][j] == 2 ){
                        for(auto& d : dir){
                            int r = i + d[0]; int c = j+d[1];
                            if ( r >= 0 && c>=0 && r<ROW && c<COL && grid[r][c] == 1 ){
                                grid[r][c] = 3;
                                fresh--;
                                flag = true;
                            } 
                        }
                    }
                }
            }
            if( !flag ) return -1;

            for(int i=0;i<ROW;i++){
                for(int j=0;j<COL;j++){
                    if(grid[i][j] == 3) grid[i][j] = 2;
                }
            }

            time++;
        }

        return time;
    }
};