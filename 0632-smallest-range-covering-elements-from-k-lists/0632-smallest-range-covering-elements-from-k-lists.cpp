class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int k = nums.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;

        int mx = INT_MIN;
        for(int i=0; i<k; i++){
            mx = max(mx, nums[i][0]);
            pq.push({nums[i][0], {i,0}});
        }

        // while(pq.size()) {
        //     cout<<pq.top().first<<" "<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
        //     pq.pop();
        // }
        // return {};

        int rst = pq.top().first;
        int rnd = mx;

        while(pq.size()){
            
            auto x = pq.top();
            int i = x.second.first;
            int idx = x.second.second;

            // cout<<x.first<<" "<<i<<" "<<idx<<endl;

            if((idx+1)<nums[i].size()) {
                pq.pop();

                // cout<<"Next check : "<<nums[i][idx+1]<<" "<<i<<" "<<idx+1<<endl;

                pq.push({nums[i][idx+1], {i,idx+1}});
                int n_rst = pq.top().first; // new range start
                mx = max(mx, nums[i][idx+1]); // new range end

                if((mx-n_rst) < (rnd-rst)){
                    rst = n_rst;
                    rnd = mx;
                }
            }
            else break;
        }
        
        return {rst,rnd};
    }
};