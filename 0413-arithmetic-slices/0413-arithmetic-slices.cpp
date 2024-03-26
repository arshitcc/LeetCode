class Solution {
public:
    

    int numberOfArithmeticSlices(vector<int>& nums) {
        
        if(nums.size() < 3) return 0;
        
        // // Brute Force : 
        // int ans = 0;
        // int idx = 0;
        // for(int idx = 0; idx<nums.size(); idx++){
        //     for(int i=idx,j=i+1,k=j+1;  i<nums.size()-2, j<nums.size()-1, k<nums.size(); i++, j++, k++ ){
        //         if(nums[j] - nums[i] == nums[k] - nums[j]) ans++;
        //         else break;
        //     }
        // }
        
        int ans = 0;
        vector<int> dp(nums.size());
        for(int i=2; i<nums.size(); i++){
            if(nums[i-1] - nums[i-2] == nums[i] - nums[i-1]){
                dp[i] += 1 + dp[i-1];
                ans += dp[i];
            }
        }
        
        return ans;
    }
};