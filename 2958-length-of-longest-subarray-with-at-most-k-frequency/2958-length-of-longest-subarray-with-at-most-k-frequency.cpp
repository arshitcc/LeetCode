class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        unordered_map<int,int> m;
        
        int i = 0;
        int j = 0;
        int maxlen = INT_MIN;
        int len = 0;
        
        while(j < nums.size()){
            
            if(m[nums[j]] < k) {
                m[nums[j]]++;
                j++;
                len++;
                maxlen = max(maxlen,len);
            }
            else {
                m[nums[i]]--;
                len--;
                i++;
            }
        }
                 
        return maxlen;
    }
};