class Solution {
public:
    
    vector<vector<int>> dp;
    // DP - Mark (Easy)
    int minSum(vector<vector<int>> &t, int i, int j){
        if(i==t.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        // cout<<t[i][j]<<" ";
        return dp[i][j] = t[i][j] + min( minSum(t,i+1,j), minSum(t,i+1,j+1));
    }
    
    int minimumTotal(vector<vector<int>>& t) {
        
        dp.resize(t.size(), vector<int> (t.size(),-1));
        return minSum(t,0,0);
        
    }
};