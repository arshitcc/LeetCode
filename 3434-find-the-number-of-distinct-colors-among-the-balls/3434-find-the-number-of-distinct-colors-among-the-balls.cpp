class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        vector<int> ans;

        unordered_map<int,int> b;
        unordered_map<int,unordered_set<int>> m;

        for(auto i : queries){
            int x = i[0];
            int y = i[1];

            int key = b[x];
            m[key].erase(x);
            if(m[key].size()==0) m.erase(key);

            b[x]=y;
            m[y].insert(x);
        
            ans.push_back(m.size());
        }

        return ans;
    }
};