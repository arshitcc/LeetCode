class Solution {
public:

    vector<int> helper(string s){
        vector<int> res;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '+' or s[i] == '-' or s[i] == '*'){
                vector<int> leftop = helper(s.substr(0,i));
                vector<int> rightop = helper(s.substr(i+1));

                for(auto x : leftop){
                    for(auto y : rightop){
                        if(s[i]=='+') res.push_back(x+y);
                        else if(s[i] == '-') res.push_back(x-y);
                        else if(s[i] == '*') res.push_back(x*y);
                    }
                }
            }
        }

        if(!res.size()) res.push_back(stoi(s));
        return res;
    }
    vector<int> diffWaysToCompute(string s) {
        return helper(s);
    }
};