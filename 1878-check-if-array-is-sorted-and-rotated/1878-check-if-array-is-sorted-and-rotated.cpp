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

        for(int x=1; x<nums.size(); x++){
            bool isRotated = true;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]!=rotated[(i+x)%nums.size()]){
                    isRotated = false;
                    break;
                }
            }
            if(isRotated) return true;
        }

        return false;
    }
};