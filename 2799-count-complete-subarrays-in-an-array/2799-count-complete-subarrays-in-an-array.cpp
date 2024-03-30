class Solution {
public:
    int sub(vector<int> &nums, int k){
        int i = 0;
        int j = 0;
        unordered_map<int,int> m;
        int count = 0;
        
        while( j < nums.size() ){
            
            m[nums[j]]++;
            
            while(m.size() > k){
                m[nums[i]]--;
                if(m[nums[i]] == 0) m.erase(nums[i]);
                i++;
            }
            
            // valid subarray
            count += j-i+1;
            j++;
            
        }
        
        return count;  
    }
    
    int countCompleteSubarrays(vector<int>& nums) {
        
        unordered_set<int> s;
        for(auto i : nums) s.insert(i);
        int k = s.size();
        
        return sub(nums,k) - sub(nums,k-1);
    }
};