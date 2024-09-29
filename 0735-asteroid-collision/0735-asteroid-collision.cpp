class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0) st.push_back(nums[i]);
            else{
                while(st.size() and st[st.size()-1]>0 and st[st.size()-1] < abs(nums[i])) st.pop_back();
                if(st.size() and st[st.size()-1] == abs(nums[i])) st.pop_back();
                else if(!st.size() or (st[st.size()-1]<0)) st.push_back(nums[i]);
            }
        }

        for(auto i : st) cout<<i<<" ";
        cout<<endl;
        return st;
    }
};