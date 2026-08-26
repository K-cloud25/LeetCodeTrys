class Solution {
public:

    void fill(vector<vector<int>>&image, int sr, int sc, int color, int cr){
        if ( sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() ) return;
        if ( cr != image[sr][sc] ) return;
        image[sr][sc] =color;
        fill(image,sr-1,sc,color,cr);
        fill(image,sr+1,sc,color,cr);
        fill(image,sr,sc+1,color,cr);
        fill(image,sr,sc-1,color,cr);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if ( image[sr][sc] == color) return image;
        fill(image, sr,sc,color, image[sr][sc]);
        return image;
    }
};