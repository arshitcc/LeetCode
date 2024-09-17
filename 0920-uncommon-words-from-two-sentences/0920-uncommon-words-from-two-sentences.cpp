class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        vector<string> ans;

        stringstream ss1(s1);
        stringstream ss2(s2);
        string x;
        unordered_map<string,int> m1;
        unordered_map<string,int> m2;
        while(ss1 >> x) m1[x]++;
        while(ss2 >> x) m2[x]++;

        for(auto [x,y] : m1) if(!m2.count(x) and y==1) ans.push_back(x);
        for(auto [x,y] : m2) if(!m1.count(x) and y==1) ans.push_back(x);
    
        return ans;
    }
};