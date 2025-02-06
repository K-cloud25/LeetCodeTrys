class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        if ( numRows == 0){
            return {{}};
        }

        if ( numRows == 1 ){
            return {{1}};
        }

        vector<vector<int>> k = generate(numRows - 1);
        vector<int> curr (numRows, 1);
        for(int i = 1; i<numRows-1; i++){
            curr[i] = k.back()[i-1]+k.back()[i];
        }
        k.push_back(curr);
        return k;
    }
};