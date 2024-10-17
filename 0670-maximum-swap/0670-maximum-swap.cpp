class Solution {
public:
    int maximumSwap(int num) {
        
        string x = to_string(num);
        int n = x.size();
        vector<int> mc(n);
        mc[n-1] = n-1;

        for(int i=n-2; i>=0; i--){
            if(x[i]<=x[mc[i+1]]) mc[i]=mc[i+1];
            else mc[i]=i;
        }

        for(int i=0; i<x.size(); i++){
            if(x[i] < x[mc[i]]) {
                swap(x[i], x[mc[i]]);
                return stoi(x);
            }
        }

        return num;
    }
};