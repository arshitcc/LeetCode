class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int,int> m;
        for(auto i : arr) m[i]++;
        
        priority_queue<pair<int,int>> pq;
        for(auto i : m) pq.push({i.second,i.first});
        
        int target = arr.size()/2;
        int original = arr.size();
        int ops = 0;
        
        while( pq.size() ){
            auto temp = pq.top(); pq.pop();
            int freq = temp.first;
            
            if(original-freq <= target) {
                ops++;
                break;
            }
            else {
                original -= freq;
                ops++;
            }
        }
        
        return ops;
    }
};