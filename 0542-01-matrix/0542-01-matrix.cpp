class Solution {
public:
    
    vector<pair<int,int>> move = {{0,1},{0,-1},{1,0},{-1,0}};
    
    void bfs(queue<pair<int,int>> &q, vector<vector<int>> &mat, vector<vector<int>> &result){
        
        while(q.size()){
            
            auto x = q.front(); q.pop();
            for(auto m : move){
                int nr = x.first + m.first;
                int nc = x.second+m.second;
                    
                if(nr>=0 and nc>=0 and nr<mat.size() and nc<mat[0].size()){
                        
                    if(mat[x.first][x.second]==0 and mat[nr][nc] == 1){
                        result[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                        
                    if(mat[x.first][x.second]==1 and mat[nr][nc]==1 and result[nr][nc]==0){
                        result[nr][nc] = 1 + result[x.first][x.second];
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        
        queue<pair<int,int>> q;
        
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        
        vector<vector<int>> result(mat.size(), vector<int> (mat[0].size()));
        bfs(q, mat, result);
        
        return result;
    }
};