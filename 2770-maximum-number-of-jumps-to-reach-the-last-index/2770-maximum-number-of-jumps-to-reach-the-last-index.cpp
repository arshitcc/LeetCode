class Solution {
public:
    
    vector<int> dp;

    int jump( int i, vector<int> &nums, int target){
        
        if( i == nums.size()-1 ) return 0;
        if( dp[i] !=-1 ) return dp[i];
        
        int jumps = INT_MIN;
        
        for(int j=i+1; j<nums.size(); j++){
            int num = nums[j]-nums[i];
            if( num >= -target and num <= target){
                jumps = max(jumps, 1 + jump(j,nums,target));
            }
        }
        
        return dp[i] = jumps;
    }
    
    int maximumJumps(vector<int>& nums, int target) {
        
        dp.resize(nums.size(), -1);
        
        int maxJumps = jump(0, nums, target);

        if(maxJumps > 0) return maxJumps;
        else return -1;
    }
};