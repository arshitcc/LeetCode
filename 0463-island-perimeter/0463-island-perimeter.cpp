class Solution {
public:
    set<pair<int,int>> visited;
    int perimtr = 0;
    
    void dfs(int i, int j, vector<vector<int>> &grid){
        
        if(i<0 or j<0 or i==grid.size() or j==grid[0].size()) return;
        if(visited.count({i,j}) == 1) return;
        
        visited.insert({i,j});
        perimtr += 4;
        
        if(j+1 <grid[0].size() and  grid[i][j+1] == 1){
            perimtr --;
            dfs(i,j+1,grid);
        }
        if(j-1>= 0 and grid[i][j-1] == 1){
            perimtr --;
            dfs(i,j-1,grid);
        }
        if(i+1 <grid.size() and  grid[i+1][j] == 1){
            perimtr --;
            dfs(i+1,j,grid);
        }
        if(i-1>=0 and grid[i-1][j] == 1){
            perimtr --;
            dfs(i-1,j,grid);
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
    
        // for(int i=0; i<grid.size(); i++){
        //     bool got = false;
        //     for(int j=0; j<grid[0].size(); j++){
        //         if(grid[i][j] == 1 and visited.count({i,j}) == 0){
        //             dfs(i,j,grid);
        //             got = true;
        //             break;
        //         }
        //     }
        //     if(got) break;
        // }
        // return perimtr;
        
        // Better : 
        int perimeter = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 1){
                    perimeter += 4;
                    if(i+1 <grid.size() and  grid[i+1][j] == 1) perimeter--;
                    if(j+1 <grid[0].size() and  grid[i][j+1] == 1) perimeter--;
                    if(i-1>=0 and  grid[i-1][j] == 1) perimeter--;
                    if(j-1>=0 and  grid[i][j-1] == 1) perimeter--;
                }
            }
        }
    
        return perimeter;
    }
};