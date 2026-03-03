class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(auto& p : prerequisites){
            indegree[p[1]]++;
            adj[p[0]].push_back(p[1]);
        }

        queue<int> q;
        for(int i=0;i<numCourses;++i){
            if ( indegree[i] == 0 ) q.push(i);
        }

        int finish = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            finish++;
            for(int i : adj[node]){
                indegree[i]--;
                if ( indegree[i] == 0 ) q.push(i);
            }
        }

        return finish == numCourses;
    }
};