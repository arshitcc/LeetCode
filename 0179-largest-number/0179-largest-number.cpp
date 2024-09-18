class Solution {
public:

    static bool cmp(int &a, int &b){
        string x = to_string(a);
        string y = to_string(b);
        string res1 = x+y;
        string res2 = y+x;
        if(res1 > res2) return true;
        else return false;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string x = "";
        for(auto i : nums) x+=to_string(i);
        if(x[0] == '0') return "0";
        return x;
    }
};