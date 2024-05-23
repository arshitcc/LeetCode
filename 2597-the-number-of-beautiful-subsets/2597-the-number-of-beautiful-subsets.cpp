class Solution {
public:
    
    int beautiful;
    
    void dfs(int i, vector<int> &nums, unordered_map<int,int> &m, int k){
        
        if(i == nums.size()){
            beautiful++;
            return;
        }
        
        dfs(i+1,nums,m,k);
        
        if(!m[nums[i]-k] and !m[nums[i] + k]){
            
            m[nums[i]]++; 
            dfs(i+1, nums, m, k);
            m[nums[i]]--; // removing the element for next indices
            
        }
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        
        beautiful = 0;
        unordered_map<int,int> m;  // O(n)
        dfs(0,nums,m,k);
        
        return beautiful-1; // excluding the empty-subset.
    }
};