class Solution {
public:
    int minAddToMakeValid(string s) {
        string x =  "";
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') x+="(";
            else {
                int n = x.size();
                if(n>0 and x[n-1]=='(') x.pop_back();
                else x+=")";
            }
        }

        return x.size();
    }
};