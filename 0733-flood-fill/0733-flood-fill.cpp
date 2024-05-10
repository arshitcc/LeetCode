class Solution {
public:
    
    // Application : MS Paint - Bucket Fill feature
    
    // set<pair<int,int>> visited; 
    // No need of visited, with help of prevColor we can check the visit,
    // as if color is same of prev, Paint It due to which repetition will not occur.
    
    
    void fill(int i, int j, int &color,int prevColor, vector<vector<int>> &image){
        
        // Outside Grid
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size()) return;
        
        // The current cell is not matching with prevColor / starting color
        if(image[i][j] != prevColor) return;

        image[i][j] = color;
        
        fill(i-1,j,color,prevColor,image);
        fill(i+1,j,color,prevColor,image);
        fill(i,j-1,color,prevColor,image);
        fill(i,j+1,color,prevColor,image);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        // If new color is equal to starting color then this can fall into infinite-recursion  :
        if(image[sr][sc] == color) return image;
        
        fill(sr, sc, color, image[sr][sc], image);
        return image;
    }
};
