class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long khushi  = 0;
        
        unordered_map<int,int> m;
        for(int i=0; i<happiness.size(); i++) m[i] = happiness[i];
        
        priority_queue<pair<int,int>> pq;
        for(auto i : m) pq.push({i.second, i.second});
        
        int turn  = 0;
        for(int i=0; i<k; i++){
            if(pq.top().first  > turn){
                khushi += pq.top().first-turn; pq.pop();
                turn++;
            }
            else break;            
        }
        
        return khushi;
        
    }
};