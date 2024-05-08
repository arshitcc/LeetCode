class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<int> dummy = score;
        sort(dummy.begin(), dummy.end());
        // 10 3 8 9 4
        // 3  4 8 9 10
        map<int,int> m;
        for(int i=dummy.size()-1; i>=0 ; i--) m[dummy[i]] = dummy.size()-i;
        
        vector<string> ans;
        
        for(int i=0; i<score.size(); i++){
            if(m[score[i]] == 1){
                ans.push_back("Gold Medal");
            }
            else if(m[score[i]] == 2){
                ans.push_back("Silver Medal");
            }
            else if(m[score[i]] == 3){
                ans.push_back("Bronze Medal");
            }
            else {
                ans.push_back(to_string(m[score[i]]));
            }
        }
        
        
        return ans;
    }
};