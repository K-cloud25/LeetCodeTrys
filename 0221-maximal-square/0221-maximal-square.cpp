class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(); 
        int m = matrix[0].size();
        vector<vector<int>> dp (n, vector<int>(m,0));
        
        for(int i = 0; i<n;i++){
            for(int j =0;j<m;j++){
                if ( i == 0 || j == 0) {
                    if ( matrix[i][j] == '1') dp[i][j] = 1;
                    else dp[i][j] = 0;
                }else{
                    if ( matrix[i][j] == '1') {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }else{
                        dp[i][j] = 0;
                    }
                }
            }
        }

        int max_val = std::ranges::max(dp | std::views::join);

        return max_val * max_val;
    }
};