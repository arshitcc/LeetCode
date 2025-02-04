class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {

        if(nums.size() ==1) return true;

        int temp = nums[0];
        for(int i=1; i<nums.size(); i++){
            int x1 = temp%2;
            int x2 = nums[i]%2;

            if((x1 and x2) or (!x1 and !x2)) return false;
            temp = nums[i];
        }

        return true;
    }
};