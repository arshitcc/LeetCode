class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string s="";
        for(int i=0; i<num.size(); i++){
            while(s.size() and k and s[s.size()-1]>num[i]) {
                s.pop_back();
                k--;
            }
            if(!s.size() and num[i]=='0')  continue;
            s.push_back(num[i]);
        }
        while(s.size() and k) {
            s.pop_back();
            k--;
        }
        if(!s.size()) return "0";
        return s;        
    }
};