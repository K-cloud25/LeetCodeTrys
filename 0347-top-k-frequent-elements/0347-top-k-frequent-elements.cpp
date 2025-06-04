typedef pair<int, int> p;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<int> res;
        priority_queue<p, vector<p>, greater<p> > pq;

        for(int n: nums) map[n]++;
        for(auto s: map){
            pq.push({s.second, s.first});
            if ( pq.size() > k ) pq.pop();
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};