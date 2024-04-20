class Solution {
public:
    
    vector<vector<int>> visited;
    vector<vector<int>> ans;
    
    pair<int,int> mincor;
    pair<int,int> maxcor;
    
    set<pair<int,int>> inserted;
    
    void dfs(int i, int j, vector<vector<int>> &graph){
        if(i<0 or j<0 or i==graph.size() or j==graph[0].size() or visited[i][j]==1 or graph[i][j]==0) return;
        visited[i][j] = 1;
        mincor = min(mincor, {i,j});
        maxcor = max(maxcor, {i,j});
        
        dfs(i+1,j,graph);
        dfs(i,j+1,graph);
        dfs(i,j-1,graph);
        dfs(i+1,j,graph);
        
        if(inserted.count(mincor) == 0 and inserted.count(maxcor) == 0){
            inserted.insert(mincor);
            inserted.insert(maxcor);
            ans.push_back({mincor.first, mincor.second, maxcor.first, maxcor.second});
        }
        
    }
    
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        
        visited.resize(n+1,vector<int>(m+1));
        
        // Graph : 
        // for(int i=0; i<land.size(); i++){
        //     for(int j=0; j<land[i].size(); j++){
        //         if(land[i][j] == 1){
        //             mincor = {INT_MAX,INT_MAX};
        //             maxcor = {INT_MIN,INT_MIN};
        //             dfs(i,j,land); 
        //         }
        //     }
        // }
        
        // Optimal  :
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j] == 1 or land[i][j] == 0) continue;
                visited[i][j] = 1;
                
                int start = i, end = j, nextStart = i, nextEnd = j;
                
                while(nextEnd < m and land[nextStart][nextEnd] == 1) nextEnd++;
                nextEnd--;
                while(nextStart < n and land[nextStart][end] == 1)  nextStart++;
                nextStart--;
                
                ans.push_back({start,end,nextStart,nextEnd});
                
                for(int x=start; x<=nextStart; x++){
                    for(int y=end; y<=nextEnd; y++){
                        visited[x][y] = 1;
                    }
                }
            }
        }
        
        return ans;
    }
};