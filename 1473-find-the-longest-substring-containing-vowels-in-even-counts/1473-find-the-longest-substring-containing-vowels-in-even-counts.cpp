class Solution {
public:
    int findTheLongestSubstring(string s) {

        // Bit-Manipulation : 
        unordered_map<int,int> m1;
        int mask = 0; // a e i o u
        m1[mask] = -1;
        int len = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='a') mask = mask^(1<<0);   
            else if(s[i]=='e') mask = mask^(1<<1); 
            else if(s[i]=='i') mask = mask^(1<<2); 
            else if(s[i]=='o') mask = mask^(1<<3); 
            else if(s[i]=='u') mask = mask^(1<<4);

            if(m1.count(mask)) len = max(len,i-m1[mask]);
            else m1[mask] = i;

        }

        return len;
        
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