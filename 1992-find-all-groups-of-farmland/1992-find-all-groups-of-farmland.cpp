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
        visited.resize(land.size()+1,vector<int>(land[0].size()+1));
        
        for(int i=0; i<land.size(); i++){
            for(int j=0; j<land[i].size(); j++){
                if(land[i][j] == 1){
                    mincor = {INT_MAX,INT_MAX};
                    maxcor = {INT_MIN,INT_MIN};
                    dfs(i,j,land); 
                }
            }
        }
        
        return ans;
    }
};