class Solution {
public:
    
    void dfs(int i, vector<vector<int>> &stones, vector<int> &visited){
        
        visited[i] = 1;
        
        for(int j=0; j<stones.size(); j++){
            if(visited[j]) continue;
            if(stones[i][0] == stones[j][0]  or stones[i][1]==stones[j][1]){
                dfs(j,stones,visited);
            }
        }
        
    }
    
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        vector<int> visited(n);
        int cc = 0;
        
        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            dfs(i,stones,visited);
            cc++;
        }
        
        return n-cc;
    }
};