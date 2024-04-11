class Solution {
public:
    string removeKdigits(string num, int k) {
        
        // 3 subs
        
        string ans;
        // stack<char> s;
        
        for(int i=0; i<num.size(); i++){

            int number = num[i]-48;
            while(ans.size() and k>0 and number<(ans[ans.size()-1]-48)){  // s.top()-48
                ans.pop_back();
                // s.pop();
                k--;
            }

            if(ans.size()==0 and number==0)  continue;

            // s.push(num[i]);
            ans.push_back(num[i]);
        }

        while(k>0 and ans.size()){
            // s.pop();
            ans.pop_back();
            k--;
        }

        if(ans.size()==0) return "0";

        return ans;        
    }
};