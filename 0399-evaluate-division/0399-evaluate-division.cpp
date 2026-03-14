class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string,double>>> adj; 
        for(int i=0; i<equations.size();i++){
            adj[equations[i][0]].emplace_back(equations[i][1], values[i]);
            adj[equations[i][1]].emplace_back(equations[i][0], 1.0/values[i]);
        }

        vector<double> res;
        for(const auto& q : queries){
            res.push_back(dfs(q[0], q[1], adj, unordered_set<string>()));
        }

        return res;
    }

    double dfs(const string& src, const string& target, unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string> visited) {
        if (!adj.count(src) || !adj.count(target)) {
            return -1.0;
        }
        if (src == target) {
            return 1.0;
        }

        visited.insert(src);

        for (const auto& [nei, weight] : adj[src]) {
            if (!visited.count(nei)) {
                double result = dfs(nei, target, adj, visited);
                if (result != -1.0) {
                    return weight * result;
                }
            }
        }

        return -1.0;
    }
};