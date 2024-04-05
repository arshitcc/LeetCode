class Solution {
public:
    string makeGood(string s) {
        
        string ans = "";
        int n = s.size();
        
        int i = 0;
        while( i <= n-1){
            int x = ans.size();
            if(x and abs(ans[x-1] - s[i]) == 32){
                ans.pop_back();
                i++;
            }
            else if( abs(s[i] - s[i+1]) !=32 ){
                ans.push_back(s[i]);
                i++;
            }
            else i += 2;
        }
        
        
        // a b B A c C
        // a A c C
        // c C
        // ""
        
        return ans;
    }
};