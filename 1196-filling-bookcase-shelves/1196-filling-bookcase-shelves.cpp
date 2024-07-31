class Solution {
public:

    int n;
    int wd;
    vector<vector<int>> dp;
    
    int solve(vector<vector<int>>& books, int i, int remainW, int maxh) {
        if(i >= n) return maxh;
        if(dp[i][remainW] != -1) return dp[i][remainW];
        
        int w = books[i][0];
        int h = books[i][1];

        int keep = INT_MAX;
        int skip = INT_MAX;

        if(w <= remainW) keep = solve(books, i+1, remainW - w, max(maxh, h));
        skip = maxh + solve(books, i+1, wd - w, h); // next level

        return dp[i][remainW] = min(keep, skip);
    }


    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        dp.resize(1005,vector<int>(1005,-1));
        n = books.size();
        wd = shelfWidth;
        int remainW = shelfWidth;

        return solve(books, 0, remainW, 0);
    }
};