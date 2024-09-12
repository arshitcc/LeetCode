class Solution {
public:
    int divide(int dividend, int divisor) {
        // Chutiya banaya tumko : 
        /*
            long long int x = (long long int)dividend/divisor;
            if(x>INT_MAX) return INT_MAX;
            else if(x<INT_MIN) return INT_MIN;
            else return x;
        */

        if(dividend == divisor) return 1;
        bool sign = false;
        if((dividend>=0 and divisor<0) or (dividend<0 and divisor>0)) sign = true;

        long n = abs(dividend);
        long d = abs(divisor);
        long quos = 0;

        while(n>=d){
            int i = 0;
            while(n > (d<<(i+1))) i++;
            quos += (1<<i);
            n-=(d<<i);
        }

        // cout<<quos;

        if(quos>INT_MAX and sign) return INT_MIN;
        if(quos>INT_MAX and !sign) return INT_MAX;
        return sign? -quos : quos;
    }
};