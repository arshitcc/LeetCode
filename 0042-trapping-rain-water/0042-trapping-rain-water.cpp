class Solution {
public:
    int trap(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> lmax(n);
        vector<int> rmax(n);
        int water = 0;

        int leftMax = -1;
        int rightMax = -1;
        for(int i=0; i<n; i++){
            if(leftMax < nums[i]) leftMax = nums[i];
            lmax[i] = leftMax;
            if(rightMax < nums[n-i-1]) rightMax = nums[n-i-1];
            rmax[n-i-1] = rightMax;
        }

        for(int i=0; i<n; i++) {
            if(nums[i] < min(lmax[i], rmax[i])){
                water += min(lmax[i],rmax[i]) - nums[i];
            }
        }

        return water;
    }
};