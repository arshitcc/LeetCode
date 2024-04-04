class Solution {
public:

    int maxDepth(string s) {
        
        int maxd = 0;
        
        int open = 0;
        
        for(int i=0; i<s.size(); i++){
            
            if(s[i] == '(') open++;
            else if(s[i] == ')') {
                maxd = max(open,maxd);
                open--;
            }
        }
        
        return maxd;
    }
};