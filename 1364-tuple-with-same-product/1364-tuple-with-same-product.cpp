class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        
        // set<int> s;
        // int ans = 0;
        // for(auto i : nums) s.insert(i);

        // for(int i=0; i<nums.size(); i++){
        //     for(int j=0; j<nums.size(); j++){
        //         if(i!=j){
        //             int p1 = nums[i]*nums[j];
        //             for(auto x : s) {
        //                 int y = p1/x;
        //                 if(x!=nums[i] and x!=nums[j] and p1%x == 0 and y!=nums[i] and y!=nums[j] and x!=y and s.count(p1/x)) {
        //                     cout<<nums[i]<<" "<<nums[j]<<" "<<x<<" "<<y<<endl;
        //                     ans++;
        //                 }
        //             }
        //         }
        //     }
        // }

        int ans = 0;
        map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                int p1 = nums[i] * nums[j];
                ans += 8 * m[p1];
                m[p1]++;
            }
        }

        return ans;
    }
};