class Solution {
public:

    vector<vector<long long>> dp;

    long long score(int parity, int idx, vector<int> &nums, int x){

        if(idx==nums.size()) return 0;
        int pn = nums[idx]%2;  //new parity

        if(dp[idx][parity]!=-1) return dp[idx][parity];

        long long ans ;
        if(parity==pn) ans = (long long) nums[idx]; 
        else ans = (long long) nums[idx]-x;

        return dp[idx][parity] = max(ans + score(pn,idx+1,nums,x), score(parity,idx+1,nums,x));
    }

    long long maxScore(vector<int>& nums, int x) {
        
        int parity = nums[0]%2;
        int idx = 0;
        dp.resize(nums.size(),vector<long long>(2,-1));
        return nums[0]+score(parity,idx+1,nums,x);

    }
};