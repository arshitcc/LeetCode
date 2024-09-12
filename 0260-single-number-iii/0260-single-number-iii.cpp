class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // unordered_map<int,int> m;
        // for(auto i : nums) m[i]++;
        // vector<int> ans;
        // for(auto x : m) if(x.second==1) ans.push_back(x.first);
        // return ans;

        int ones = 0;
        int twoes = 0;

        long long num = 0;
        for(auto i : nums) num = num^i;

        num = (num&(num-1))^num; // gives the rightmost bit to differentiate with number

        for(auto i : nums){
            if( i&num ) ones ^= i;
            else twoes ^= i;
        }

        return {ones,twoes};
    }
};