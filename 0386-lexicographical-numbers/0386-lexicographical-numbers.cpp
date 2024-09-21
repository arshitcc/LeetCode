class Solution {
public:

    void lexicoNums(int num, int n, vector<int> &ans){
        if(num<=n and num!=0){
            ans.push_back(num);
            for(int i=0; i<=9; i++){
                lexicoNums(10*num + i ,n,ans);
            }
        }
        
        if(num<=n and num==0){
            for(int i=1; i<=9; i++){
                lexicoNums(i,n,ans);
                // Mostly some use 10*num + i, n, nums
            }
        }
        
        return;
    }
    vector<int> lexicalOrder(int n) {
        
        vector<int> ans;
        lexicoNums(0,n,ans);
        return ans;

    }
};