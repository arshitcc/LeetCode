class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n);
        ans[n-1] = -1;

        int n2 = nums2.size();
        vector<int> nxt(n2);
        nxt[n2-1] = -1;
        stack<int> st;
        st.push(nums2[n2-1]);

        for(int i=n2-2; i>=0; i--){
            while(st.size() and nums2[i] > st.top()) st.pop();

            if(st.size()) nxt[i] = st.top();
            else nxt[i] = -1;

            st.push(nums2[i]);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n2; j++){
                if(nums1[i] == nums2[j]) {
                    ans[i] = nxt[j];
                    break;
                }
            }
        }

        return ans;
    }
};