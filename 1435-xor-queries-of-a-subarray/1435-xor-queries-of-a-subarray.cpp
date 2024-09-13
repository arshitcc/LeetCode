class Solution {
public:

    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for(int i=1; i<n; i++) prefix[i]= prefix[i-1]^arr[i];
    
        vector<int> ans;
        for(auto i : q){
            int x = i[0];
            int y = i[1];
            int z;
            if(x == 0) z = prefix[y];
            else z = prefix[x-1]^prefix[y];
            ans.push_back(z);
        }
        return ans;
    }
};