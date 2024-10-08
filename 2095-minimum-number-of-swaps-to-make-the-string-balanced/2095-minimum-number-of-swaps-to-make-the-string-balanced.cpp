class Solution {
public:
    int minSwaps(string s) {
        
        int open = 0;

        for(auto i : s){
            if(i == '[') open++;
            else if(open>0) open--;
        }

        return (open+1)/2;
        /*
            ][ : 1
            ]][[ : 1
            ]]][[[ : 2
            ]]]][[[[ : 4 
        */

        stack<char> st;
        for(auto i : s){
            if(i=='[') st.push(i);
            else {
                if(st.size() and st.top()=='[') st.pop();
            }
        }

        int n = st.size();
        return (n+1)/2;


    }
};