class Solution {
public:
    int isPrefix(string s1, string s2){
        if(s1[0]!=s2[0]) return -1;
        int i=0;
        int j=0;
        while(i<s1.size() and j<s2.size()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else break;
        }
        return i;
    }

    int digits(int num){
        int dg=0;
        while(num){
            dg++;
            num = num/10;
        }
        return dg;
    }

    int longestCommonPrefix(vector<int>& nums1, vector<int>& nums2) {
        
        // Brute Force:
        // int maxl = 0;
        // for(int i=0; i<nums1.size(); i++){
        //     for(int j=0; j<nums2.size(); j++){
        //         string s1 = to_string(nums1[i]);
        //         string s2 = to_string(nums2[j]);
        //         if(isPrefix(s1,s2)!=-1){
        //             maxl = max(maxl,isPrefix(s1,s2));
        //         }
        //     }
        // }
        // return maxl;

        set<int> s;
        for(int i=0; i<nums1.size(); i++){
            int num = nums1[i];
            while(num){
                s.insert(num);
                num=num/10;
            }
        }
        int maxl = 0;
        for(int i=0; i<nums2.size(); i++){
            int num = nums2[i];
            while(num){
                if(s.find(num)!=s.end()){
                    maxl = max(maxl,digits(num));
                }
                num=num/10;
            }
        }
        return maxl;
    }
};