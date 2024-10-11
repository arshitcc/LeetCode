class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        int maxw = 0;
        int n = nums.size();
        stack<int> st;
        st.push(n-1);

        for(int i=n-1; i>=0; i--){
            if(nums[i]>nums[st.top()]) st.push(i);
        }

        for(int i=0; i<n; i++){
            while(st.size() and nums[i]<=nums[st.top()]){
                maxw = max(maxw, st.top()-i);
                st.pop();
            }  
        }

        return maxw;
    }
};