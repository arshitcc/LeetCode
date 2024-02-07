class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(auto i : s) m[i]++;

        priority_queue<pair<int,char>> pq;
        for(auto i : m) pq.push({i.second,i.first});

        string ans="";
        while(pq.size()){
            auto x = pq.top(); pq.pop();
            for(int i=0; i<x.first; i++ ) ans.push_back(x.second);
        }
        
        return ans;
    }
};
