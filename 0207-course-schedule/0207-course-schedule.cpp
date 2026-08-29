class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(auto& it : prerequisites){
            indeg[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if( indeg[i] == 0 ) q.push(i);
        }
        
        int fi=0;
        while(!q.empty()){
            int t = q.front(); q.pop();
            fi++;
            for(int i : adj[t]){
                indeg[i]--;
                if ( indeg[i]==0){
                    q.push(i);
                }
            }
        }

        return fi == numCourses;
    }
};