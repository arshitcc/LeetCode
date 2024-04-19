class Solution {
public:

//     void dfs(int i, int j, vector<vector<char>> &grid, set<pair<int, int>> &visited) {
        
//         if (i<0 || j<0 || i == grid.size() || j == grid[0].size() || grid[i][j] == '0') return;
        
//         if(visited.count({i,j}) == 1) return;
        
//         visited.insert({i, j});
        
//         dfs(i+1, j, grid,visited);
//         dfs(i-1, j, grid,visited);
//         dfs(i, j+1, grid,visited);
//         dfs(i, j-1, grid,visited);
        
//     }
    
//     void bfs( int i, int j, vector<vector<char>> &grid, set<pair<int, int>> &visited ){
        
//         queue<pair<int,int>> q;
//         q.push({i,j});
        
//         while( q.size() ){
            
//             auto temp = q.front(); q.pop();
//             int x = temp.first;
//             int y = temp.second;
            
//             vector<pair<int,int>> neighbors = {{x,y+1}, {x,y-1}, {x-1,y}, {x+1,y}};
            
//             for(auto n : neighbors){
//                 int row = n.first;
//                 int col = n.second;
//                 if( row>=0 and col>=0 and row<grid.size() and col<grid[0].size() and grid[row][col]=='1' and visited.count(n) == 0 ){
//                     q.push(n);
//                     visited.insert(n);
//                 }
//             }
//         }
//     }
    
    void dfs( int i, int j, vector<vector<char>> &grid){
        
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size()) return;

        if(grid[i][j] == '0') return; // visited;
        
        grid[i][j] = '0'; // mark visted
        
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
        
    }
    
    void bfs( int i, int j, vector<vector<char>> &grid){
        
        grid[i][j] = '0'; // mark visited
        
        queue<pair<int,int>> q;
        q.push({i,j});
        while(q.size()){
            auto temp = q.front(); q.pop();
            int x = temp.first, y = temp.second;
            vector<pair<int,int>> neighbors = {{x,y+1}, {x,y-1}, {x-1,y}, {x+1,y}};
            
            for(auto n : neighbors){
                int row = n.first;
                int col = n.second;
                
                if( row>=0 and col>=0 and row<grid.size() and col<grid[0].size() and grid[row][col]=='1'){
                    grid[row][col] = '0';  // mark visited
                    q.push(n);
                }
            }
        }
        
    }


    int numIslands(vector<vector<char>>& grid) {
        
        set<pair<int,int>> visited;
        
        // Clearly its asking number of connected components
        int cc = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
            
                if(grid[i][j] == '0') continue;
                // another way of checking visited node.
                
                cc++;
                // dfs(i,j,grid);
                bfs(i,j,grid);
                
                // if (visited.count({i, j}) == 0 && grid[i][j] == '1') {
                //     cc++;
                //     // dfs(i, j, grid, visited);
                //     bfs(i, j, grid, visited);
                // }
            }
        }
        
        return cc;
    }
    
    
};