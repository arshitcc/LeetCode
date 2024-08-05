class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        map<string, pair<int,int>> m;
        int n = arr.size();

        for(int i=0; i<n; i++){
            if(m.count(arr[i])){
                auto x = m[arr[i]];
                m[arr[i]] = {i, x.second+1};
            }
            else m[arr[i]] = {i,1};
        }

        vector<pair<int,int>> v;
        for(auto [x,y] : m) if(y.second == 1) v.push_back(y);
        sort(v.begin(), v.end());

        if(k<=v.size()) return arr[v[k-1].first];
        return "";

    }
};