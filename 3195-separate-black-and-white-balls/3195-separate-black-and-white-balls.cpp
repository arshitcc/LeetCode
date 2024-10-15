class Solution {
public:

    long long minimumSteps(string s) {
        
        long long swaps = 0;

        int ones = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1') ones++;
            else swaps += ones;
        }

        // // Insertion Sort : TLE : (568 / 581)

        // for(int i=0; i<s.size()-1; i++){
        //     int  j = i;
        //     while(j>=0 and (s[j]>s[j+1])){
        //         swap(s[j], s[j+1]);
        //         swaps++;
        //         j--;
        //     }
        // }

        return swaps;
    }
};