class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // unordered_map<int,int> m;
        // for(auto i : nums) m[i]++;
        // for(auto x : m){
        //     if(x.second==1) return x.first;
        // }

        // return 0;

        // int n = nums.size();
        // int ans = 0;
        // for(int i=0; i<32; i++){
        //     int count = 0;
        //     for(int j=0; j<n; j++){
        //         if( nums[j]&(1<<i) ){
        //             count++;
        //         }
        //     }
        //     if(count%3 == 1){
        //         ans = ans|(1<<i);
        //     }
        // }
        // return ans;

        // sort(nums.begin(), nums.end());
        // for(int i=1; i<nums.size(); i+=3){
        //     if(nums[i]!=nums[i-1]){
        //         return nums[i-1];
        //     }
        // }
        // return nums[nums.size()-1];


        // magic : XD
        int ones = 0;
        int twoes = 0; 
        int n = nums.size();
        for(int i=0; i<n; i++){
            ones = (ones^nums[i])&(~twoes);
            twoes = (twoes^nums[i])&(~ones);
        }
        return ones;
    }
};