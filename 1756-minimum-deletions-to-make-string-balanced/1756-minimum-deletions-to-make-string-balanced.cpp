class Solution {
public:
    int minimumDeletions(string s) {
        
        stack<char>st ; 
        int ops = 0 ;
        st.push(s[0]);

        for(int i=1; i<s.size(); i++){
            if(st.size() and (st.top() == 'b' and s[i] == 'a')){
                st.pop();
                ops++;
            }
            else st.push(s[i]);
        }
        return ops ;
    }
};