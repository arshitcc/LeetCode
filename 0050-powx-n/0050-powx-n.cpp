class Solution {
public:

    double num(double x, int n){
        if(!n) return 1;
        return x*num(x,n-1);
    }

    double myPow(double x, int n) {

        // IMP-Base Conditons:  
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;

        bool neg = false;
        if(n<0) {
            neg = true;
            n*=-1;
        }
        double number = num(x,n);
        if(!neg) return number;
        else return 1.0/(double)number;
    }
};