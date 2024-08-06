class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> v(26);
        for(auto i : word) v[i-'a']++;
        for(auto i : v) cout<<i<<" ";
        cout<<endl;
        sort(v.rbegin(), v.rend());
        

        int start = 8;
        int ans = 0;
        int count = 1;

        for(auto i : v){
            if(start == 0){ // mc
                start = 8;
                count++;
            }
            ans += count*i;
            start--;
        }

        return ans;
    }
};