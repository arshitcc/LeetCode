class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
       
       if(target.size()!=arr.size()) return false;
       unordered_map<int,int> m1, m2;
       for(auto i : target) m1[i]++;
       for(auto i : arr) m2[i]++;

       for(auto [x,y] : m1){
        if(m2[x]!=y) return false;
       }
       return true;
    }
};