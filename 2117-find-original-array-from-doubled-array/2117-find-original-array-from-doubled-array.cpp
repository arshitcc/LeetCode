class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {

        int n = changed.size();
        if(n%2==1) return {};
        unordered_map<int,int> m;
        for(auto i : changed) m[i]++;

        vector<int> ans;
        sort(changed.begin(), changed.end());

        for(auto i : changed){
            if(m[i] == 0) continue;
            if(m[i*2] and m[i]){
                ans.push_back(i);
                m[i]--;
                m[i*2]--;
            }
            else return {};
        }

        return ans; 
    }
};