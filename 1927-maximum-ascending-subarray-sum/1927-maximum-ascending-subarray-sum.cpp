class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int maxs = nums[0];

        for(int i=0; i<nums.size(); i++){
            int temp = nums[i];
            int sum = nums[i];
            for(int j=i+1; j<nums.size(); j++){
                if(temp < nums[j]) {
                    temp = nums[j];
                    sum+=nums[j];
                }
                else break;
            }
            maxs = max(maxs, sum);
        }

        return maxs;
    }
};