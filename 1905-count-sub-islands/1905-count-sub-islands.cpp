class Solution {
public:

    bool match = true;
    
    void dfs(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2){
        
        if(i<0 or j<0 or i==grid2.size() or j==grid2[0].size() or grid2[i][j] == 0) return;
        
        if(grid1[i][j] == 0) {
            match = false;
            return;
        }
        grid2[i][j]=0; // visited
        
        dfs(i+1,j,grid1,grid2);
        dfs(i,j+1,grid1,grid2);
        dfs(i,j-1,grid1,grid2);
        dfs(i-1,j,grid1,grid2);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int cc = 0;
        for(int i=0; i<grid1.size(); i++){
            for(int j=0; j<grid1[0].size(); j++){
                
                if(grid2[i][j]==1){
                    dfs(i,j,grid1,grid2);
                    if(match) cc++;
                    match = true;
                }
            }
        }
        
        return cc;
    }
};