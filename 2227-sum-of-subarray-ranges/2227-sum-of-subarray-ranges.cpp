class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        // O(n) is hell
            
        int n = nums.size();
        stack<int> st;
        vector<int> pse(n); pse[0]=-1;
        vector<int> pge(n); pge[0]=-1;
        vector<int> nge(n); nge[n-1]=n;
        vector<int> nse(n); nse[n-1]=n;

        for(int i=n-1; i>=0; i--){
            while(st.size() and nums[st.top()] < nums[i]) st.pop();
            nge[i] = (st.size())? st.top() : n;
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--){
            while(st.size() and nums[st.top()] > nums[i]) st.pop();
            nse[i] = (st.size())? st.top() : n;
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=0; i<n; i++){
            while(st.size() and nums[st.top()] <= nums[i]) st.pop();
            pge[i] = (st.size())? st.top() : -1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0; i<n; i++){
            while(st.size() and nums[st.top()] >= nums[i]) st.pop();
            pse[i] = (st.size())? st.top() : -1;
            st.push(i);
        }
        while(!st.empty()) st.pop();

        long long sum = 0;
        for(int i=0;i<n;i++){
            long long leftMin=i-pse[i],rightMin=nse[i]-i;
            long long leftMax=i-pge[i],rightMax=nge[i]-i;
            sum+=(leftMax*rightMax-leftMin*rightMin)*nums[i];
        }

        return sum;
    }
};