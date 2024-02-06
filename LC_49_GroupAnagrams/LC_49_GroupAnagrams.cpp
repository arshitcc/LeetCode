class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        
        int n = v.size();
        map<string,vector<string>> m;

        for(int i=0;i<n;i++){
            string str = v[i];
            sort(str.begin(),str.end());
            m[str].push_back(v[i]);
        }
        // Mapping :
        // abt:bat 
        // aet:eat tea ate 
        // ant:tan nat

        vector<vector<string>> ans;
        for(auto x : m){
            vector<string> vc = x.second;
            ans.push_back(vc);
        }

        return ans;
    }
};
