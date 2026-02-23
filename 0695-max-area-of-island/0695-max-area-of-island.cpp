class Solution {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    int dfs(vector<vector<int>>& grid, int i, int j){
        queue<pair<int,int>> q;
        grid[i][j] = 0;
        int cnt = 1;
        q.push({i,j});
        while(!q.empty()){
            auto it = q.front(); q.pop();
            for(int k=0;k<4;k++){
                int nr = it.first + dir[k][0];
                int nc = it.second + dir[k][1];
                if( nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1 ){
                    q.push({nr,nc});
                    grid[nr][nc] = 0;
                    cnt++;
                }
            }
        }
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=0;
        for(int i = 0; i<grid.size(); i++){
            for(int j=0;j<grid[0].size();j++){
                if( grid[i][j] == 1 ){
                    m = max(m,dfs(grid,i,j));
                }
            }
        }
        return m;
    }
};