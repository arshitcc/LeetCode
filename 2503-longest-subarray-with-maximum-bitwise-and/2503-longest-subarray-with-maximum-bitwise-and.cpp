class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int maxLen = 0;
        int mx = 0;
        int len = 0;
        for(auto i : nums){
            if(i > mx){
                mx=i;
                maxLen = 1;
                len=0;
            }

            if(mx == i) len++;
            else len = 0;

            maxLen = max(maxLen,len);
        }
        return maxLen;

        // BF : 
        // int len = 0;
        // int max_and = nums[0];
        // int n = nums.size();
        // for(int i=0; i<n; i++){
        //     int res = nums[i];
        //     if(res > max_and){
        //         max_and = res;
        //         len = 1;
        //     }
        //     for(int j=i+1; j<n; j++){
        //         res = res&nums[j];
        //         if(res == 0) break;
        //         if((res > max_and)){
        //             max_and = res;
        //             len = j-i+1;
        //         }
        //         else if(res == max_and) len = max(len,j-i+1);
        //     }
        // }
        // return len ? len:1;
    }
};