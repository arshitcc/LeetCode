class Solution {
public:
    
    
    int ways(int num, int target, int nos){
        if(nos>=2 and target==0) return 1;
        if(num > target) return -1;
        else return max(num*ways(num,target-num,nos+1), ways(num+1,target,nos));
    }
    
    int integerBreak(int n) {
        return ways(1,n,0);
    }
};