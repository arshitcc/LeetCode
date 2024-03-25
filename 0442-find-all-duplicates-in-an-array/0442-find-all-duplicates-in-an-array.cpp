class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        // Count Sort
        vector<int> vc;
        int n =  nums.size();
        int i=0;
        while(i<n){
            int correctIdx = nums[i]-1;
            if(nums[i]==nums[correctIdx]) i++;
            else swap(nums[i],nums[correctIdx]);
        }
        for(int i=0;i<n;i++) if(i!=nums[i]-1) vc.push_back(nums[i]);
        return vc;
    }
};