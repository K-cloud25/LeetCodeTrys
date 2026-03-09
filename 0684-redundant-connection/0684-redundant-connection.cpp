class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ind(edges.size()+1,0);
        vector<vector<int>> adj(edges.size()+1);

        for(auto& it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            ind[it[0]]++;
            ind[it[1]]++;
        }

        queue<int> q;
        for (int i = 1; i <= edges.size(); i++) {
            if (ind[i] == 1) q.push(i);
        }

        while(!q.empty()){
            int node = q.front(); q.pop();
            ind[node]--;
            for(int nei : adj[node]){
                ind[nei]--;
                if(ind[nei]==1){
                    q.push(nei);
                }
            }
        }

        for(int i=edges.size()-1; i>=0;i--){
            int v = edges[i][0]; int u = edges[i][1];
            if(ind[v]==2 && ind[u]){
                return {v,u};
            }
        }
        return {};
    }
};