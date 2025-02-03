class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int inc = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            int temp = nums[i];
            for(int j=i+1; j<nums.size(); j++){
                if(temp<nums[j]) {
                    inc = max(inc,j-i+1);
                    temp = nums[j];
                }
                else break;
            }
        }

        int dec = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            int temp = nums[i];
            for(int j=i+1; j<nums.size(); j++){
                if(temp>nums[j]) {
                    dec = max(dec,j-i+1);
                    temp = nums[j];
                }
                else break;
            }
        }
        
        int ans = max(inc, dec);
        if(ans == INT_MIN) return 1;
        return ans;
    }
};