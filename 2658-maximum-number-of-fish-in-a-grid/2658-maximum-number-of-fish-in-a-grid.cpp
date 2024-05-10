class Solution {
public:
    
    int fish = 0;
    vector<vector<int>> visited;
    
    void dfs(int i, int j, vector<vector<int>> &grid){
        if(i<0 or j<0 or i==grid.size() or j==grid[0].size() or grid[i][j] == 0) return;
        if(visited[i][j] == 1) return;
        
        visited[i][j] = 1;
        fish += grid[i][j];
        
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        dfs(i-1,j,grid);
        
    }
    
    
    int findMaxFish(vector<vector<int>>& grid) {
       
        visited.resize(grid.size(), vector<int> (grid[0].size()));
        int maxfish = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]!=0){
                    dfs(i,j,grid);
                    maxfish = max(maxfish,fish);
                    fish = 0;
                }
            }
        }
        
        return maxfish;
    }
};