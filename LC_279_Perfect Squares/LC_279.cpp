class Solution {
public:
    vector<int> dp;

    // Top-Down :
    int f(int n){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];

        int ans = INT_MAX;
        for(int i=1; i<=sqrt(n); i++){
            ans = min(ans,1+f(n-i*i));
        }
        return dp[n]=ans;
    }

    int numSquares(int n) {
        dp.resize(10004,-1);
        return f(n);
    }
};
