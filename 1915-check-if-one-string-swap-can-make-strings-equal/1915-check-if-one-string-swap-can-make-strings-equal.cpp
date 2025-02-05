class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        for(int i=0; i<s2.size(); i++){
            string temp = s2;
            for(int j=i+1; j<s2.size(); j++){
                swap(s2[i],s2[j]);
                if(s1 == s2) return true;
                s2 = temp;
            }
        }
        return false;
    }
};