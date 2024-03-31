class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        if(minK > maxK) return 0;
        
        int i = 0;
        int j = 0;
        unordered_map<int,int> m;
        long long count = 0;
        
        int minIdx = -1;
        int maxIdx = -1;
        int out = -1;
        
        while( j < nums.size() ){
            
            if(nums[j] == minK) minIdx = j;
            if(nums[j] == maxK) maxIdx = j;
            if(not (nums[j] >= minK and nums[j] <= maxK) )  out = j;
            
            int pos = min(minIdx, maxIdx);
            if(pos !=-1){ // both found
                int ans = pos - out;
                if(ans > 0) count += ans;
                // if (ans < 0) no new valid subarray 
            }
            
            j++;
            
        } 
        
        /*  Self Test Case : 
            [1,1,5,2,3,7,5,1,3,2]
            1
            5
        */
        return count;
    }
};