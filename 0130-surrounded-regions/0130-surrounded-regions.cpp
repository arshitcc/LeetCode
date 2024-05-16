class Solution {
public:
    
    void dfs(int i, int j, vector<vector<char>> &grid){
        
        if(i<0 or j<0 or i==grid.size() or j==grid[0].size() or grid[i][j] == 'X' or grid[i][j] == 'Y') return;
        
        grid[i][j] = 'Y';
        
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        dfs(i-1,j,grid);
        
    }
    
    void solve(vector<vector<char>>& board) {
        
        // Reverse Approach : from Border Zeroes, do a BFS/DFS and mark all zeroes from there as Non-Capturable
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O') dfs(i,0,board); //  0th-column
            if(board[i][n-1] == 'O') dfs(i,n-1,board); // last-column
        }
        
        for(int j=0; j<n; j++){
            if(board[0][j] == 'O') dfs(0,j,board); // 0th-row
            if(board[m-1][j] == 'O') dfs(m-1,j,board);// last-row
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X'; // reaminging O are markable
                if(board[i][j] == 'Y') board[i][j] = 'O';//  Y are non-markable so re-make them 'O'
            }
        }
        
        
    }
};