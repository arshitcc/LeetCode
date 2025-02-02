class Solution {
public:
    bool check(vector<int>& nums) {
        
        bool isSorted = true;

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]){
                isSorted = false;
                break;
            }
        }

        if(isSorted) return true;

        vector<int> rotated = nums;
        sort(nums.begin(), nums.end());

        int x = 1;
        int n = nums.size();

        
        while(x < n){
            bool isRotated = true;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]!=rotated[(i+x)%n]){
                    isRotated = false;
                    break;
                }
            }
            if(isRotated) return true;
            x++;
        }

        return false;
    }
};