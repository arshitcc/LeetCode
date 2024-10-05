class Solution {
public:

    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<int> rankers = arr;
        sort(rankers.begin(),rankers.end());
        unordered_map<int,int> m;

        int rank = 1;
        for(int i=0; i<rankers.size(); i++){
            if(m.count(rankers[i])) continue;
            m[rankers[i]] = rank++;
        }

        for(int i=0; i<arr.size(); i++) arr[i] = m[arr[i]];
        return arr;
    
    }
};