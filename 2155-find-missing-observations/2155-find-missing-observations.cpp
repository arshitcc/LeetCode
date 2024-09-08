class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int m = rolls.size();
        int m_sum = 0;
        for(auto i : rolls) m_sum += i;
        int n_sum = mean*(n+m) - m_sum;
        
        int extra = n_sum%n;
        int val = n_sum/n;
        if(val<1 or val>6) return {};
        if(extra and val+1 > 6) return {};

        vector<int> ans(n);
        for(int i=0; i<n; i++){
            if(i<extra) ans[i] = val+1;
            else ans[i] = val;
        }

        return ans;
    }
};