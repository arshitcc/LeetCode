class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int> , greater<int>> group;

        for(auto i : intervals){
            int start = i[0];
            int end = i[1];
            if(group.size() and start > group.top()) group.pop();
            group.push(end);
        }

        return group.size();
        

        /* TLE : 25/35 */
        
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> times;
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> waiting;

        // for(auto i : intervals) times.push({i[0], i[1]});

        // int groups = 0;
        // while(times.size()){
        //     auto x = times.top(); times.pop();
        //     int st = x.first;
        //     int end = x.second;

        //     groups++;
        //     while(times.size()){
        //         auto y = times.top(); times.pop();
        //         int wst = y.first;
        //         int wend = y.second;
        //         if(end >= wst) waiting.push(y);
        //         else end = wend;
        //     }
        //     while(waiting.size()){
        //         times.push(waiting.top()); waiting.pop();
        //     }
        // }
        // return groups;
    }
};