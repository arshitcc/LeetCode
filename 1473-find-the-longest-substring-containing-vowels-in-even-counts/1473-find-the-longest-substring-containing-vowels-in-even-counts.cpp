class Solution {
public:
    int findTheLongestSubstring(string s) {
        
        // CWM approach : 
        unordered_map<string,int> m;
        string curr = "00000";
        m[curr] = -1;
        int maxLen = 0;

        vector<int> state(5,0);

        for(int i=0; i<s.size(); i++){
            if(s[i]=='a') state[0] = (state[0]+1)%2;   // state[0]^1
            else if(s[i]=='e') state[1] = (state[1]+1)%2; // state[1]^1
            else if(s[i]=='i') state[2] = (state[2]+1)%2; // state[2]^1
            else if(s[i]=='o') state[3] = (state[3]+1)%2; // state[3]^1
            else if(s[i]=='u') state[4] = (state[4]+1)%2; // state[4]^1

            curr = "";
            for(auto i : state) curr+=(to_string(i));

            if(m.count(curr)) maxLen = max(maxLen, i-m[curr]);
            else m[curr] = i;
        }

        return maxLen;
    }
};