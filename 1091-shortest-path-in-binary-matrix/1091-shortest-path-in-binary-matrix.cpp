class Solution {
public:
    
    
    int dfs(int i, int j, vector<vector<int>> &graph, vector<vector<int>> visted, int len){
        
        if(i == graph.size()-1 and j==graph[0].size()-1) return len+1;
        if(i<0 or j<0 or i==graph.size() or j==graph[0].size() or graph[i][j]==1 or visted[i][j]==1) return INT_MAX;
        
        visted[i][j] = 1;
        len++;
        int l1 = dfs(i-1,j-1,graph,visted,len);
        int l2 = dfs(i-1,j,graph,visted,len);
        int l3 = dfs(i-1,j+1,graph,visted,len);
        int l4 = dfs(i,j+1,graph,visted,len);
        int l5 = dfs(i+1,j+1,graph,visted,len);
        int l6 = dfs(i+1,j,graph,visted,len);
        int l7 = dfs(i+1,j-1,graph,visted,len);
        int l8 = dfs(i,j-1,graph,visted,len);  
        
        return min({l1,l2,l3,l4,l5,l6,l7,l8});
    }
    
    int bfs(vector<vector<int>> grid){
        
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size()));
        queue<pair<int,int>> q;
        
        
        q.push({0,0});
        visited[0][0] = 1;
        
        vector<pair<int,int>> direction = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
        
        int length = 0;
        
        while(q.size()){
            
            int n = q.size();
            length++;
            
            for(int itr=1; itr<=n; itr++){
                auto [x,y] = q.front(); q.pop();
                
                if(x == grid.size()-1 and y == grid[0].size()-1) return length;
                
                for(auto [a,b] : direction){
                    int i = x+a;
                    int j = y+b;
                    
                    if(i>=0 and j>=0 and i<grid.size() and j<grid[0].size() and visited[i][j]==0 and grid[i][j]==0 ){
                        visited[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
        }
        
        return -1;
        
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1 or grid[n-1][m-1]==1) return -1;
        
        // // Memory Limit Exceeded : 
        // int len = 0;
        // vector<vector<int>> visited(n,vector<int>(m));
        // int res =  dfs(0,0,grid,visited,len);
        // if(res == INT_MAX) return -1;
        // else return ans;
        
        return bfs(grid);
        
    }
};