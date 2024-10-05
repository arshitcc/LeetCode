class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int sum = 0;
        for(auto i : nums) sum = (sum+i)%p;
        int target = sum%p;

        if(target == 0) return 0;

        unordered_map<int,int> m;
        
        m[0] = -1;
        int len = INT_MAX;
        int curr = 0;

        for(int i=0; i<nums.size(); i++){
            curr = (curr+nums[i])%p;
            int x = (curr -target + p)%p;
            if(m.count(x)) len = min(len,i-m[x]);
            m[curr]=i;
        }

        if(len == nums.size()) return -1;
        return len;

    }
};