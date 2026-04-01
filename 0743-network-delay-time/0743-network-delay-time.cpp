class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> edges;
        for( const auto& time : times)
            edges[time[0]].emplace_back(time[1], time[2]);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> heap;
        heap.push({0,k});
        set<int> visit;
        int t = 0;
        while(!heap.empty()){
            auto curr = heap.top(); heap.pop();
            if ( visit.count(curr.second) ) continue;
            visit.insert(curr.second);
            t=curr.first;

            if (edges.count(curr.second)) {
                for (const auto& next : edges[curr.second]) {
                    int n2 = next.first, w2 = next.second;
                    if (!visit.count(next.first)) {
                        heap.push({curr.first + next.second, next.first});
                    }
                }
            }
        }
        return visit.size() == n ? t : -1;
    }
};