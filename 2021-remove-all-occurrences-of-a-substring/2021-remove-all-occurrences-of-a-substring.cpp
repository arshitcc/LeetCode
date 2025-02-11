class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        string ans;
        for(auto c: s){
            ans.push_back(c);
            while(ans.find(part) < ans.size()){
                for(int i = 0;i<n;i++) ans.pop_back();
            }
        }
        return ans;
    }
};