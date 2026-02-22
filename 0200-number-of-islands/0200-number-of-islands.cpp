class Solution {
public:
    int dir[4][2] = {{0,1}, {0,-1},{1,0},{-1,0}};

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(); int cols = grid[0].size();
        int islands=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        queue<pair<int,int>> q;
        grid[i][j] = '0';
        q.push({i,j});
        while(!q.empty()){
            auto it = q.front();q.pop();
            for(int k=0;k<4;k++){
                int nr = it.first + dir[k][0];
                int nc = it.second + dir[k][1];
                if( nr >=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc] == '1' ){
                    q.push({nr,nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};