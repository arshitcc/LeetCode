class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        set<int> s;
        for(auto i : nums) s.insert(i);
        
        int ans = 1;
        for(int i=1; i<=INT_MAX; i++){
            if(s.find(i)==s.end()){
                ans =  i;
                break;
            }
        }
        
        return ans;
    }
};