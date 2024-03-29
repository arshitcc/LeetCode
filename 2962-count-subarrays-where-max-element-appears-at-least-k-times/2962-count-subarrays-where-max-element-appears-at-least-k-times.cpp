class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        long long count = 0;
        
        map<int,int> m;
        
        
        int mx = INT_MIN;
        for(auto i : nums)  mx = max(mx,i);
        
        int i = 0;
        int j = 0;
        
        while(j < nums.size() ){
            
            if(nums[j] == mx) m[mx]++;
            j++;
            
            while(m[mx] >=k ){
                if(nums[i] == mx){
                     m[mx]--;
                }
                i++; // skip not max elements
            }
            
            count += i; // The number of times 'i' got shifted.
        }
        
        return count;
        
    }
};