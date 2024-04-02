class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if( s.size() != t.size() ) return false;
        
        unordered_map<char,char> ms, mt;
        
        for(int i=0; i<s.size(); i++){
            
            if( ms.count(s[i]) == 1 ) {
                if (ms[s[i]] != t[i]) return false;
            }
            else{
                if (mt.count(t[i]) == 1) return false;
                else {
                    ms[s[i]] = t[i];
                    mt[t[i]] = s[i];
                }
            }
            
        }
        return true; 
    }
};