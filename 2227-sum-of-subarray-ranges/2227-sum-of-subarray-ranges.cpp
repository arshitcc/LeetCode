class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            int minEle = nums[i];
            int maxEle = nums[i];
            for(int j=i; j<nums.size(); j++){
                minEle = min(minEle,nums[j]);
                maxEle = max(maxEle,nums[j]);
                sum += (maxEle - minEle);
            }
        } 
        return sum;
    }
};