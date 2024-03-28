class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size()==0 || s.size()==1) return s.size();
        
        unordered_map<char,int> m;
        
        int i = 0;
        int j = 0;
        int len = 0;
        int maxlen = INT_MIN;
        
        while(j < s.size()){
            
            if(m[s[j]] == 0){
                m[s[j]]++;
                j++;
                len++;
                maxlen = max(maxlen, len);
            }
            else{
                m[s[i]]--;
                len--;
                i++;
            }
        }
        
        return maxlen;
    }
};