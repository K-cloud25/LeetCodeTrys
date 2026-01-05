class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> t;
        for( vector<int> p : trips ){
            t.push_back({p[1], p[0]});
            t.push_back({p[2], -p[0]});
        }
        int curr=0;
        sort(t.begin(), t.end());
        for( pair<int,int> p : t){
            curr+=p.second;
            if ( curr>capacity ) return false;
        }
        return true;
    }
};