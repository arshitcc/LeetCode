class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        unordered_map<int,int> m;
        for(auto i : arr){
            int ele = (i%k + k)%k;
            m[ele]++;
        }
        if(m[0]%2!=0) return false;
        for(auto i : m){
            int ele = i.first;
            int rem = k - ele;
            if(ele!=0 and m[ele]!=m[rem]) return false;
        }
        return true;
    }
};