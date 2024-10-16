class Solution {
public:

    vector<vector<int>> dp;
    unordered_map<int,int> m;

    bool solve(int idx, int prev, vector<int> &stones){

        if(stones[idx] == stones[stones.size()-1]) return true;
        if(!m.count(stones[idx]) or prev<0) return false;
        if(dp[idx][prev]!=-1) return dp[idx][prev];

        bool ans = false;
        if(m.count(stones[idx] + prev-1)) 
        ans = ans or solve(m[stones[idx] + prev-1], prev-1, stones);

        if(m.count(stones[idx] + prev) and prev!=0) 
        ans = ans or solve(m[stones[idx] + prev], prev, stones);

        if(m.count(stones[idx] + prev+1)) 
        ans = ans or solve(m[stones[idx] + prev+1], prev+1, stones);

        return dp[idx][prev] = ans;
    }

    bool canCross(vector<int>& stones) {
        
        dp.resize(stones.size(), vector<int> (2005,-1));
        for(int i=0; i<stones.size(); i++) m[stones[i]] = i;

        int k = 1;
        int curr = 1;
        if(!m.count(curr)) return false;
        return solve(curr,k,stones);

    }
};