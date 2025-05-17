typedef pair<int,int> p;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i : nums)
            mp[i]++;
        vector<int> res;
        priority_queue<p, vector<p>, greater<p>> pq;
        
        for(auto i : mp){
            pq.push({i.second, i.first});
            if ( pq.size() > k )
                pq.pop();
        }

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};