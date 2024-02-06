class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // Brute force : O(n^2)
        // int n = nums.size();
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]+nums[j]==target) return {i,j};
        //     }
        // }
        // return {};

        // Using Map :
        unordered_map<int,int> map;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int remTarget = target - nums[i];
            if(map.find(remTarget)!=map.end()){ 
                ans.push_back(i);
                ans.push_back(map[remTarget]);
                // return {i, map[remTarget] }
            }
            else map[nums[i]] = i;
        }
        return ans;
    }
};
