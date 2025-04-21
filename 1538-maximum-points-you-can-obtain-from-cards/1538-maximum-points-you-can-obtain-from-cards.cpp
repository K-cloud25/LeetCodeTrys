class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = accumulate(cardPoints.begin(), cardPoints.begin()+k,0);
        int res = sum;
        int n=cardPoints.size();
        for (int i = k - 1; i>=0; i--){
            sum -=cardPoints[i];
            sum += cardPoints[n-k+i];
            res=max(res, sum);
        }
        return res;
    }
};