class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for(auto i : s){
            int n = ans.size();
            if(n>0 and (i>=48 and i<=57) and (ans[n-1]>=97 and ans[n-1]<=122)) ans.pop_back();
            else ans.push_back(i);
        }
        return ans;
    }
};