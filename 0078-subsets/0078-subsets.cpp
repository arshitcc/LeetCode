class Solution {
public:

void helper(vector<vector<int>> &v, vector<int> &nums, vector<int> ans, int idx){

    if(idx==nums.size()){
        v.push_back(ans);
        cout<<endl;
        return;
    }
    helper(v,nums,ans,idx+1);
    ans.push_back(nums[idx]);
    helper(v,nums,ans,idx+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> ans;
        vector<vector<int>> finalans;
        helper(finalans, nums, ans , 0);
        return finalans;

    }
};