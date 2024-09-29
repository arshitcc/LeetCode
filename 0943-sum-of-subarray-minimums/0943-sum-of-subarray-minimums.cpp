class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();

        vector<int> nse(n);
        nse[n-1] = n;
        stack<int> st;
        st.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(st.size() and arr[st.top()] >= arr[i]) st.pop();
            if(st.size()) nse[i]=st.top();
            else nse[i]=n;
            st.push(i);
        }

        vector<int> pse(n);
        pse[0]=-1;
        stack<int> ss;
        ss.push(0);
        for(int i=1; i<n; i++){
            while(ss.size() and arr[ss.top()] > arr[i]) ss.pop();
            if(ss.size()) pse[i]=ss.top();
            else pse[i]=-1;
            ss.push(i);
        }
        
        int sum = 0;
        int mod = 1e9+7;

        for(int i=0; i<n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            sum = (sum + (left*right*1LL*arr[i])%mod)%mod;
        }

        return sum;
    }
};