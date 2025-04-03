class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long m=0,mdif=0,mval=nums[0]*1LL;
        for(int a=1;a<nums.size()-1;a++) {
            mdif=max(mdif,mval-nums[a]*1LL);
            mval=max(mval,nums[a]*1LL);
            m=max(m,mdif*nums[a+1]);
        }
        return m;
    }
};