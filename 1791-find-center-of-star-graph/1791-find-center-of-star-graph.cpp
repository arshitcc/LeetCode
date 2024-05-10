class Solution {
public:
    
    int findCenter(vector<vector<int>>& edges) {
        
        // Edge-1
        int a = edges[0][0];
        int b = edges[0][1];
        
        // Edge-2
        int c = edges[1][0];
        int d = edges[1][1];
        
        // Any one has to be common if its a star graph,
        return (a==c || a==d)? a : b;
        
        // return (c==a || c==b)? c : d;
        
        
        
        // // Brute Force : 
        // map<int,int> m;
        // for(int i=0; i<edges.size(); i++){
        //     m[edges[i][0]]++;
        //     m[edges[i][1]]++;
        // }
        // int ans = 0;
        // for(auto x : m){
        //     if(x.second == edges.size()) {
        //         ans = x.first;
        //     }
        // }
        // return ans;
        
    }
};