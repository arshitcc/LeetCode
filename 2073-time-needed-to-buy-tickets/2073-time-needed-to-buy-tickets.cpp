class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int time = 0;
        
        queue<pair<int,int>> q;
        
        for(int i=0; i<tickets.size(); i++) q.push({i,tickets[i]});
        
        while(q.size()) {
            auto temp = q.front(); q.pop();
            
            temp.second = temp.second-1;
            time++;
            
            if(temp.second>0) q.push(temp);
            if(temp.first==k and temp.second==0) break;
            
        }
        
        return time;     
    }
};