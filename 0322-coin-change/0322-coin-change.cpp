class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if ( amount == 0 ) return 0;

        queue<int> q;
        q.push(0);
        vector<bool> seen(amount+1, false);
        seen[0]=true;
        int steps = 0;
        
        while( !q.empty() ){
            steps+=1;
            int it = q.size();
            for(int i=0;i<it;i++){
                int cur = q.front(); q.pop();
                for(int coin : coins ){
                    int nxt = cur + coin;
                    if ( amount == nxt ) return steps;
                    if ( nxt > amount || seen[nxt] ) continue;
                    seen[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        return -1;
    }
};