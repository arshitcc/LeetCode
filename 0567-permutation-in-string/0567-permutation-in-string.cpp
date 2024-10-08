class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size() > s2.size()) return false;
        sort(s1.begin(), s1.end());
        int x = s1.size();
        for(int i=0; i<=s2.size()-x; i++){
            string str = s2.substr(i,x);
            sort(str.begin(),str.end());
            if(s1 == str) return true;
        }

        return false;
    }
};