class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> v(26);
        for(auto i : word) v[i-'a']++;
        sort(v.rbegin(), v.rend());
        

        int slots = 8;
        int ans = 0;
        int min_push = 1;

        for(auto i : v){
            if(slots == 0){ // mc
                slots = 8;
                min_push++;
            }
            ans += min_push*i;
            slots--;
        }

        return ans;
    }
};