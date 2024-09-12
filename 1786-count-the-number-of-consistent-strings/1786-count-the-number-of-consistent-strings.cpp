class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        unordered_set<char> s;
        for(auto i : allowed) s.insert(i);
        int count = 0;
        for(auto i : words){
            bool flag = true;
            for(auto x : i){
                if(!s.count(x)){
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};