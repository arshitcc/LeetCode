class Solution {
public:
    
    set<pair<int,int>> visited;
    vector<vector<int>> visit;
    int ans = 0;
    
    void dfs(int i, int j, vector<vector<int>> &grid){
        
        if(i<0 or j<0 or i==grid.size() or j==grid[0].size() or grid[i][j]==0 ) return;
        
        // set is using complexity of O(logn) and
        // Unordered_set doesn't have comparator function for pair<int,int>
        // if(visited.count({i,j}) == 1) return;
        // visited.insert({i,j});
        
        if(visit[i][j]==1) return;
        visit[i][j] = 1;
        
        ans++;
        
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        visit.resize(grid.size(), vector<int>(grid[0].size()));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid);
                    maxArea = max(maxArea,ans);
                    ans = 0;
                }
            }
        }
        
        return maxArea;
    }
};