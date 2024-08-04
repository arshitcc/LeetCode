class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int> v1;
        for(int i=0; i<n; i++){
            int sum = nums[i];
            v1.push_back(sum);
            for(int j=i+1; j<n; j++){
                sum += nums[j];
                v1.push_back(sum);
            }
        }

        sort(v1.begin(), v1.end());
        long long x = 0;
        for(int i=left-1; i<=right-1; i++) x=(x%(1000000007) + v1[i])%1000000007;

        return x;
    }
};