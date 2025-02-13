class Solution {
public:
    int getSum(int n) {
        int res = 0;
        while (n) {
            res += (n % 10);
            n /= 10;
        }
        return res;
    }

    int maximumSum(vector<int>& nums) {

        vector<int>v(82,-1);
        int maxi = -1;

        for (auto num : nums) {
            int s = getSum(num);
            if(v[s]==-1) v[s]=num;
            else{
                maxi=max(maxi,v[s]+num);
                v[s]=max(v[s],num);
            }
        }
        return maxi;
    }
};