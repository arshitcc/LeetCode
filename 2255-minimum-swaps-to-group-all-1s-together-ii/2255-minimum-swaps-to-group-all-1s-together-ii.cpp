class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] == 1) ones++;
            nums.push_back(nums[i]);
        }

        int currOnes = 0;
        for(int i=0; i<=ones-1; i++) if(nums[i]==1) currOnes++;
        int ans = ones-currOnes;  // swaps

        int i = 1;
        int j = ones;
        while(j<nums.size()){
            if(nums[i-1] == 1) currOnes--;
            if(nums[j] == 1) currOnes++;
            ans = min(ans, ones-currOnes);
            i++;
            j++;
        }
        return ans;
    }
};