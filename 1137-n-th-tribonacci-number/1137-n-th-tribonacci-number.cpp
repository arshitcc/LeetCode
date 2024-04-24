class Solution {
public:
    vector<int> dp;

    int fibo(int i){
        if(i==0) return 0;
        if(i==1 ||i==2) return 1;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=fibo(i-1)+fibo(i-2)+fibo(i-3);
    }

    int tribonacci(int n) {
        dp.resize(n+1,-1);
        return fibo(n);
    }
};