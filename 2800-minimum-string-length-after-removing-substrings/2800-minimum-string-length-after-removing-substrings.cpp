class Solution {
public:
    int minLength(string s) {
        
        stack<char> st;
        
        for(auto i : s){
            if(st.size() and i=='B' and st.top()=='A') st.pop();
            else if(st.size() and i=='D' and st.top()=='C') st.pop();
            else st.push(i);
        }

        return st.size();
        
    }
};