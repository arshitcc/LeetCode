class Solution {
public:

    int m = 1e9+7;
    long long power(long long x, long long n, long long ans){
        if(n == 0) return ans;
        if(n%2 == 0) return power((x*x)%m, n/2, ans);
        else return power(x, n-1, (ans*x)%m);
    }

    int countGoodNumbers(long long n) {

        long long ans = power(20,n/2,1);
        if(n%2 ==0) return ans;
        else return (ans*5)%m;

        // TLE : 
        // if(n==1) return 5;
        // long long prod = 1;
        // bool odd = false;
        // if(n%2 != 0) odd = true;
        // for(int i=1;i<=n/2; i++) prod = (prod*20)%(1000000007);
        // if(odd) return (prod*4)%(1000000007);
        // return prod;
    }
};